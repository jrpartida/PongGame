#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(exEngineInterface* pEngine, int id)
	: mEngine(pEngine)
	,identifier(id)
{
}

GameObject::~GameObject()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Destroy();

		delete pComponent;
	}
}

void GameObject::Initialize()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Initialize();
	}
}

void GameObject::AddComponent(Component* pComponent)
{
	mComponents.push_back(pComponent);
}

