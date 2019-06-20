#pragma once
#include "Component.h"
#include "IPhysicsCollisionEvent.h"
#include "COGBoxShape.h"
#include "COGTransform.h"
#include "COGCircleShape.h"

// COGPhysics - lets move around
class COGPhysics : public Component
{
public:

	static std::vector<COGPhysics*> mPhysicsComponents;

public:

	COGPhysics(GameObject* pGO, bool bGenerateCollisionEvents);

	virtual ComponentType GetType() const;

	virtual void Initialize() override;

	virtual void Destroy() override;

	virtual void Update(float fDeltaT);

	bool IsColliding(COGPhysics* pOther);

	void AddCollisionEventListener(IPhysicsCollisionEvent* pEvent);

	void SetNewVelocity(Vector2 newVel);

	Vector2& GetVelocity();

	int bSide;

private:

	Vector2 mVelocity;
	COGTransform * mTransform;
	COGBoxShape* mBoxShape;
	COGCircleShape* mCircleShape;


	bool mGenerateCollisionEvents;
	std::vector<IPhysicsCollisionEvent*> mCollisionEventListeners;

};


