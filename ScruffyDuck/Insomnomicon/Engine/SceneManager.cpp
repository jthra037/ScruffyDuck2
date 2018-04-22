#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
{
	SceneList = std::vector<Scene*>();
}

Scene* SceneManager::GetScene(const char* searchName)
{
	for each (Scene* sceneptr in SceneList)
	{
		if (sceneptr->name == searchName)
		{
			return sceneptr;
		}
	}

	return nullptr;
}