#include "COGTransform.h"

COGTransform::COGTransform(GameObject* pGO) : Component(pGO)
{
}

COGTransform::~COGTransform()
{
}

ComponentType COGTransform::GetType() const { return ComponentType::Transform; }

Vector2& COGTransform::GetPosition() { return mPosition; }


void COGTransform::SetPosition(Vector2 position)
{
	mPosition.x = position.x;
	mPosition.y = position.y;

}

/*

void COGPlayerController::Update()
{
	InputManager* pInputManager = InputManager::GetInstance()

	if (pInputManager->IsUp())
	{
		// touch COGPhysics or COGTransform to go up
	}
	else if (pInputManager->IsDown())
	{
		// touch COGPhysics or COGTransform to go down
	}
}

*/