#pragma once
#include "InputManager.h"

#include "Engine/Public/SDL.h"

InputManager::InputManager() 
{
}

InputManager::~InputManager() {}


void InputManager::Update()
{
	int nKeys;
	const Uint8 *pState = SDL_GetKeyboardState(&nKeys);

	for (auto it = mStates.begin(); it != mStates.end(); ++it)
	{
		it->second = pState[it->first];
	}
}

void InputManager::PushKey(SDL_Scancode key)
{
	mStates[key] = false;
}

bool InputManager::GetState(SDL_Scancode key) const
{
	return mStates.find(key)->second;
}

