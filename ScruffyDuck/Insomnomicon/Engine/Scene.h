#pragma once
#include "ObjectManager.h"
#include "_AllComponents.h"

class Scene
{
public:
	//Scene();
	Scene(const char* = "Scene");
	virtual void Update(const float& = 0);
	virtual void BuildScene() = 0;
	sf::Time GetRuntime();
	const char* name;

protected:
	ObjectManager* _objectManager;

private:
	sf::Time runtime;
	sf::Clock timer;
};