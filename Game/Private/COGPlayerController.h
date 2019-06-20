#include "InputManager.h"
#include "Component.h"

#include "Engine/Public/SDL.h"

class COGPlayerController: public Component
{
public:

	COGPlayerController(GameObject* pGO);

	virtual ComponentType GetType() const;

	static std::vector<COGPlayerController*> mPlayerControllerComponents;

	virtual void Update();

	virtual void Initialize();

	virtual void Destroy();

	virtual void SetKeys(SDL_Scancode up, SDL_Scancode down);

	SDL_Scancode mUpKey;
	SDL_Scancode mDownKey;
};

