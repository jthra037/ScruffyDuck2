#pragma once
#include "Scene.h"

class MenuScene : 
	public Scene
{
public:
	MenuScene(const char* = "Menu");
	//void Update(const float&);
	void BuildScene();
};