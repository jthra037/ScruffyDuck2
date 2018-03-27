#pragma once
#include "ObjectManager.h"
#include "_AllComponents.h"

class Scene
{
public:
	Scene();
	virtual void Update(const float&) = 0;
	virtual void BuildScene() = 0;

protected:
	ObjectManager* _objectManager;
};