#pragma once
#include "COGPlayerController.h"
#include "COGTransform.h"
#include "Math.h"

#include "Engine/Public/SDL.h"

COGPlayerController::COGPlayerController(GameObject* pGO) : Component(pGO)
{
}

ComponentType COGPlayerController::GetType() const
{
	return ComponentType::PlayerController;
}

void COGPlayerController::Initialize()
{
	AddToComponentVector(mPlayerControllerComponents);
}

void COGPlayerController::Destroy()
{
	RemoveFromComponentVector(mPlayerControllerComponents);
}

void COGPlayerController::SetKeys(SDL_Scancode up, SDL_Scancode down)
{
	InputManager* pInputManager = InputManager::getInstance();
	pInputManager->PushKey(up);
	pInputManager->PushKey(down);

	mUpKey = up;
	mDownKey = down;
}

void COGPlayerController::Update()
{
	InputManager* pInputManager = InputManager::getInstance();
	if (pInputManager->GetState(mUpKey))
	{
		// touch COGPhysics or COGTransform to go up
		COGTransform* pTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
		Vector2 newPos = pTransform->GetPosition();
		
		newPos.y -= 10.0f;
		if (newPos.y <= 50) { newPos.y = 51; }

		pTransform->SetPosition(newPos);
	}
	else if (pInputManager->GetState(mDownKey))
	{
		// touch COGPhysics or COGTransform to go down
		COGTransform* pTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
		Vector2 newPos = pTransform->GetPosition();

		newPos.y += 10.0f;
		if (newPos.y >= 550) { newPos.y = 549; }

		pTransform->SetPosition(newPos);
	}
}

std::vector<COGPlayerController*> COGPlayerController::mPlayerControllerComponents;