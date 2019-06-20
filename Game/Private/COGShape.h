#pragma once
#include "Component.h"
#include "Engine\Public\EngineInterface.h"

// COGShape - our baseclass for shapes
class COGShape : public Component
{
public:

	static std::vector<COGShape*> mShapeComponents;

public:

	COGShape(GameObject* pGO);

	virtual void Initialize() override;

	virtual void Destroy() override;

	virtual void Render() = 0;


protected:

	// TODO - add a color variable here!
	exColor shapeColor;

};


