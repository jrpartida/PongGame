#pragma once

#include <vector>

#include "ComponentType.h"

class exEngineInterface;
class Component;

// our game object, it's just a collection of components - that's it!
class GameObject 
{
public:

	GameObject(exEngineInterface* pEngine, int id);
	~GameObject();

	void Initialize();

	void AddComponent(Component* pComponent);

	template<class T>
	T* FindComponent(ComponentType eType)
	{
		for (Component* pComponent : mComponents)
		{
			if (pComponent->GetType() == eType)
			{
				return (T*)pComponent;
			}
		}

		return nullptr;
	}

private:
	std::vector<Component*> mComponents;

public:
	exEngineInterface * mEngine;
	int identifier;

};

