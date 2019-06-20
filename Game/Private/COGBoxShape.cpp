#include "COGBoxShape.h"

#include "COGTransform.h"

COGBoxShape::COGBoxShape(GameObject* pGO, float fWidth, float fHeight)
	: COGShape(pGO)
	, mWidth(fWidth)
	, mHeight(fHeight)
{
}

ComponentType COGBoxShape::GetType() const 
{ 
	return ComponentType::BoxShape; 
}

void COGBoxShape::Render()
{
	// tell EngineX to draw me
	COGTransform* pTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
	Vector2& myTransform = pTransform->GetPosition();

	exVector2 topLeft, bottomRight;

	topLeft.x = myTransform.x - (mWidth * 0.5f);
	topLeft.y = myTransform.y - (mHeight * 0.5f);

	bottomRight.x = myTransform.x + (mWidth * 0.5f);
	bottomRight.y = myTransform.y + (mHeight * 0.5f);

	mGO->mEngine->DrawBox(topLeft, bottomRight, shapeColor, 0);


}

float& COGBoxShape::GetHeight()
{
	return mHeight;
}

float& COGBoxShape::GetWidth()
{
	return mWidth;
}