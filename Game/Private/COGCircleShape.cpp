#include "COGCircleShape.h"

#include "COGTransform.h"

COGCircleShape::COGCircleShape(GameObject* pGO, float fRadius)
	: COGShape(pGO)
	, mRadius(fRadius)
{
}

ComponentType COGCircleShape::GetType() const
{
	return ComponentType::CircleShape; 
}

void COGCircleShape::Render()
{
	// tell EngineX to draw me
	COGTransform* pTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
	Vector2& circleTransform = pTransform->GetPosition();

	exVector2 centerPoint;
	centerPoint.x = circleTransform.x - (mRadius * 0.5f);
	centerPoint.y = circleTransform.y - (mRadius * 0.5f);

	mGO->mEngine->DrawCircle(centerPoint, mRadius, shapeColor, 0);
}

float COGCircleShape::GetRadius()
{
	return mRadius;
}