#include "Singleton.cpp"

#include "Engine/Public/SDL.h"

#include <map>

class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;

protected:
	InputManager();
	~InputManager();

public:
	void Update();

	void PushKey(SDL_Scancode key);
	bool GetState(SDL_Scancode key) const;

private:
	std::map<SDL_Scancode, bool> mStates;

};

InputManager* Singleton<InputManager>::mObject = nullptr;

