#pragma once
#include "Component.h"
#include "Math.h"

class COGTransform : public Component
{
public:

	COGTransform(GameObject* pGO);
	~COGTransform();

	virtual ComponentType GetType() const;

	void SetPosition(Vector2 position);

	Vector2& GetPosition();

private:
	Vector2 mPosition;

};

