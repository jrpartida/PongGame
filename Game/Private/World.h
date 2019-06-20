#pragma once
#include "GameObject.h"
#include "COGPhysics.h"
#include "COGPlayerController.h"
#include <vector>

class exEngineInterface;

class World
{
public:

	World(exEngineInterface* pEngine);

	void Create();

	void Destroy();

	void Update(float fDeltaT);

	GameObject* CreateBarrier(Vector2 v2Transform, int id);

	GameObject* CreateBarrierTop();

	GameObject* CreateBarrierBot();

	GameObject* CreatePaddle(Vector2 v2Transform, SDL_Scancode up, SDL_Scancode down, int id);

	GameObject* CreatePaddleOne();

	GameObject* CreatePaddleTwo();

	GameObject* CreateBall();

	GameObject* CreateScore();

	void UpdateScore(int score1 = 0, int score2 = 0);

private:

	exEngineInterface * mEngine;
	std::vector<GameObject*> mGameObjects;

	int p1Score;
	int p2Score;

};
