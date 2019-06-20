#pragma once
#include "COGShape.h"
#include "Engine\Public\EngineTypes.h"
// COGBoxShape - box
class COGBoxShape : public COGShape
{
public:

	COGBoxShape(GameObject* pGO, float fWidth, float fHeight);

	virtual ComponentType GetType() const;

	virtual void Render() override;

	float& GetWidth();
	float& GetHeight();

private:

	float mWidth;
	float mHeight;

};