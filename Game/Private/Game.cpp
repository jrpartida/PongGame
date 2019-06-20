//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Pin Ball Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine(nullptr)
	, mFontID(-1)
	, mUp(false)
	, mDown(false)
	, mWorld(nullptr)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "cour.ttf", 20 );

	mWorld = new World(mEngine);
	mWorld->Create();
	
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	// Black background screen
	color.mColor[0] = 111;
	color.mColor[1] = 132;
	color.mColor[2] = 127;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	InputManager::getInstance()->Update();
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{
	//mWorld->Create();
	mWorld->Update(fDeltaT);
	
	// Player 1 paddle controls
	//if (mUp) 
	//{
	//	player1->Move(-paddleSpeed * fDeltaT);
	//}
	//else if (mDown) {
	//	player1->Move(paddleSpeed * fDeltaT);
	//}

	// Draw objects on screen
	//mEngine->DrawCircle(ball->getCenter(), ball->getRadius(), ball->getColor(), 0);
	//mEngine->DrawBox(player1->getP1Poisition(), player1->getP2Poisition(), player1->getColor(), 0);
	//mEngine->DrawBox(player2->getP1Poisition(), player2->getP2Poisition(), player2->getColor(), 0);
}
