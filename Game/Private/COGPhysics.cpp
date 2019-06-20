#include "COGPhysics.h"
#include "COGBounce.h"
#include "World.h"


COGPhysics::COGPhysics(GameObject* pGO, bool bGenerateCollisionEvents)
	: Component(pGO)
	, mGenerateCollisionEvents(bGenerateCollisionEvents)
	, bSide(0)
{
}

ComponentType COGPhysics::GetType() const 
{ 
	return ComponentType::Physics; 
}

void COGPhysics::Initialize()
{
	mTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
	mBoxShape = mGO->FindComponent<COGBoxShape>(ComponentType::BoxShape);
	mCircleShape = mGO->FindComponent<COGCircleShape>(ComponentType::CircleShape);
	if (mGenerateCollisionEvents)
	{
		mVelocity = { 200.0f, 200.0f };
	}

	AddToComponentVector(mPhysicsComponents);
}

void COGPhysics::Destroy()
{
	RemoveFromComponentVector(mPhysicsComponents);
}

void COGPhysics::Update(float fDeltaT)
{
	// integrate velocity
	Vector2& myPosition = mTransform->GetPosition();

	myPosition.x += mVelocity.x * fDeltaT;
	myPosition.y += mVelocity.y * fDeltaT;


	// check collisions
	if (mGenerateCollisionEvents)
	{
		for (COGPhysics* pPhysicsOther : COGPhysics::mPhysicsComponents)
		{
			// do not collide with self
			if (pPhysicsOther == this)
			{
				continue;
			}

			// TODO - maybe have IsColliding produce a vector/struct that contains the normal and then pass that into OnCollision?
			const bool bResult = IsColliding(pPhysicsOther);

			if (bResult)
			{
				for (IPhysicsCollisionEvent* pCollisionEventListener : mCollisionEventListeners)
				{
					pCollisionEventListener->OnCollision(this, pPhysicsOther);
				}
			}
		}
	}
}

bool COGPhysics::IsColliding(COGPhysics* pOther)
{
	if (mCircleShape != nullptr && pOther->mBoxShape != nullptr)
	{
		// check a circle colliding with a box
		// Other object values
		Vector2 mPos = pOther->mTransform->GetPosition();
		float mH = pOther->mBoxShape->GetHeight() * 0.5f;
		float mW = pOther->mBoxShape->GetWidth() * 0.5f;

		// ball values
		Vector2 cCenter = mTransform->GetPosition();
		float cRadius = mCircleShape->GetRadius() * 0.5;

		
		//Check if its colliding on the first paddle
		if (pOther->mGO->identifier == 1)
		{
			if (cCenter.x - cRadius <= mPos.x + mW)
			{
				if (cCenter.y - cRadius >= mPos.y - mH && cCenter.y + cRadius <= mPos.y + mH)
				{
					// set a bounce value so I know where to bounce
					bSide = 1;
					return true;
				}

			}
		}
		//Check if its colliding on the second paddle
		else if (pOther->mGO->identifier == 2)
		{
			if (cCenter.x + cRadius >= mPos.x - mW)
			{
				if (cCenter.y - cRadius >= mPos.y - mH && cCenter.y + cRadius <= mPos.y + mH)
				{
					bSide = 2;
					return true;

				}
			}

		}
		// check if its colliding on the top
		else if (pOther->mGO->identifier == 3)
		{
			if (cCenter.y - cRadius <= mPos.y + mH)
			{
				bSide = 3;
				return true;

			}
		}
		// check if its colliding on the bot
		else if (pOther->mGO->identifier == 4)
		{
			if (cCenter.y + cRadius >= mPos.y - mH)
			{
				bSide = 4;
				return true;
			}
		}
	}

	// we don't cover the other cases
	// maybe assert here?

	return false;
}

void COGPhysics::AddCollisionEventListener(IPhysicsCollisionEvent* pEvent)
{
	mCollisionEventListeners.push_back(pEvent);
}

void COGPhysics::SetNewVelocity(Vector2 newVel)
{
	mVelocity = { newVel.x, newVel.y };
}

Vector2& COGPhysics::GetVelocity()
{
	return mVelocity;
}

std::vector<COGPhysics*> COGPhysics::mPhysicsComponents;