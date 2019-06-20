#pragma once
// our interface that allows COGPhysics to talk to anyone
class COGPhysics;

class IPhysicsCollisionEvent
{
public:

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther) = 0;

};
