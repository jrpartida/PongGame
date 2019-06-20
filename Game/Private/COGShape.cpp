#include "COGShape.h"

COGShape::COGShape(GameObject* pGO)
	: Component(pGO)
	, shapeColor({224, 71, 53, 255})

{
}

void COGShape::Initialize()
{
	AddToComponentVector(mShapeComponents);
}

void COGShape::Destroy()
{
	RemoveFromComponentVector(mShapeComponents);
}

std::vector<COGShape*> COGShape::mShapeComponents;