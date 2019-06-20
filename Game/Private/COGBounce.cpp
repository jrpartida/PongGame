#include "COGBounce.h"

#include "COGPhysics.h"

#include "Math.h"

ComponentType COGBounce::GetType() const 
{ 
	return ComponentType::Bounce; 
}

void COGBounce::Initialize()
{
	COGPhysics* pPhysics = mGO->FindComponent<COGPhysics>(ComponentType::Physics);

	// add myself to the list of objects that are interested in collisions
	// COGPhysics is able to interface with us because we inherit from IPhysicsCollisionEvent
	
	pPhysics->AddCollisionEventListener(this);
}

void COGBounce::OnCollision(COGPhysics* pMe, COGPhysics* pOther)
{
	// tell pMe to bounce by setting our velocity to a new amount
	// Bounce to the right
	if (pMe->bSide == 1 || pMe->bSide == 2)
	{
		Vector2 currentVel = pMe->GetVelocity();
		Vector2 newVel = { -currentVel.x, currentVel.y };
		pMe->SetNewVelocity(newVel);		
	}
	// Bounce to the left
	else if (pMe->bSide == 3 || pMe->bSide == 4)
	{
		Vector2 currentVel = pMe->GetVelocity();
		Vector2 newVel = { currentVel.x, -currentVel.y };
		pMe->SetNewVelocity(newVel);

	}
}