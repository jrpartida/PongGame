#pragma once
#include "Component.h"
#include "IPhysicsCollisionEvent.h"

// COGBounce - where we make the ball bounce
class COGBounce : public Component, public IPhysicsCollisionEvent
{
public:

	COGBounce(GameObject* pGO)
		: Component(pGO)
	{
	}

	virtual ComponentType GetType() const;

	virtual void Initialize() override;

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther) override;

};

