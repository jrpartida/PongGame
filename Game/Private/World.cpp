#include "World.h"

#include "Engine/Public/SDL.h"

#include "COGBounce.h"

World::World(exEngineInterface* pEngine)
	: mEngine(pEngine)
	, p1Score(0)
	, p2Score(0)
{
}

void World::Create()
{
	mGameObjects.push_back(CreateBarrierTop());
	mGameObjects.push_back(CreateBarrierBot());
	mGameObjects.push_back(CreatePaddleOne());
	mGameObjects.push_back(CreatePaddleTwo());
	mGameObjects.push_back(CreateBall());
}


void World::Destroy()
{
	for (GameObject* pGameObject : mGameObjects)
	{
		delete pGameObject;
	}

	mGameObjects.clear();
}

void World::Update(float fDeltaT)
{
	// run simulation first
	for (COGPlayerController* pPlayerController : COGPlayerController::mPlayerControllerComponents)
	{
		pPlayerController->Update();
	}

	for (COGPhysics* pPhysics : COGPhysics::mPhysicsComponents)
	{
		pPhysics->Update(fDeltaT);
	}

	// then render everything
	for (COGShape* pShape : COGShape::mShapeComponents)
	{
		pShape->Render();
	}

}

GameObject* World::CreateBarrier(Vector2 v2Transform, int id)
{
	const float fBarrierWidth = 800.0f;
	const float fBarrierHeight = 10.0f;

	GameObject* pBarrier = new GameObject(mEngine, id);

	COGTransform* pTransform = new COGTransform(pBarrier);
	pTransform->SetPosition(v2Transform);
	pBarrier->AddComponent(pTransform);

	COGShape* pBoxShape = new COGBoxShape(pBarrier, fBarrierWidth, fBarrierHeight);
	pBarrier->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pBarrier, false);
	pBarrier->AddComponent(pPhysics);

	pBarrier->Initialize();

	return pBarrier;
}

GameObject* World::CreateBarrierTop()
{
	Vector2 v2Transform = {400.0f, 1.0f};
	return CreateBarrier(v2Transform, 3);
}

GameObject* World::CreateBarrierBot()
{
	Vector2 v2Transform = { 400.0f, 599.0f };
	return CreateBarrier(v2Transform, 4);
}

// create our paddle
GameObject* World::CreatePaddle(Vector2 v2Transform, SDL_Scancode up, SDL_Scancode down, int id)
{
	const float fPaddleWidth = 30.0f;
	const float fPaddleHeight = 100.0f;

	GameObject* pPaddle = new GameObject(mEngine, id);

	COGPlayerController* p1Controller = new COGPlayerController(pPaddle);
	p1Controller->SetKeys(up, down);
	pPaddle->AddComponent(p1Controller);

	COGTransform* pTransform = new COGTransform(pPaddle);
	pTransform->SetPosition(v2Transform);
	pPaddle->AddComponent(pTransform);

	COGBoxShape* pBoxShape = new COGBoxShape(pPaddle, fPaddleWidth, fPaddleHeight);
	pPaddle->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pPaddle, false);
	pPaddle->AddComponent(pPhysics);

	pPaddle->Initialize();

	return pPaddle;
}

// Create a Paddle with individual twiks for each one
GameObject* World::CreatePaddleOne()
{
	Vector2 v2Transform = { 30.0f, 300.0f };
	return CreatePaddle(v2Transform, SDL_SCANCODE_W, SDL_SCANCODE_S, 1);
}

GameObject* World::CreatePaddleTwo()
{
	Vector2 v2Transform = { 770.0f, 300.0f };
	return CreatePaddle(v2Transform, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, 2);
}

// create ball (notice how it will generate events)
GameObject* World::CreateBall()
{
	const float fBallRadius = 24.0f;

	GameObject* pBall = new GameObject(mEngine, 0);

	COGTransform* pTransform = new COGTransform(pBall);

	Vector2 v2Transform = { 400.0f, 300.0f };
	pTransform->SetPosition(v2Transform);

	pBall->AddComponent(pTransform);

	COGCircleShape* pSphereShape = new COGCircleShape(pBall, fBallRadius);
	pBall->AddComponent(pSphereShape);

	COGPhysics* pPhysics = new COGPhysics(pBall, true);
	pBall->AddComponent(pPhysics);

	COGBounce* pBounce = new COGBounce(pBall);
	pBall->AddComponent(pBounce);

	pBall->Initialize();

	return pBall;
}

GameObject* World::CreateScore()
{
	return nullptr;
}

void World::UpdateScore(int score1, int score2)
{
	p1Score += score1;
	p2Score += score2;
}
