#pragma once
#include <vector>

class Scene;

class SceneManager
{
public:
	SceneManager();

	Scene* ActiveScene;
	std::vector<Scene*> SceneList;

	Scene* GetScene(const char*);
};

