#pragma once
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	scene = std::vector<Object*>();
}

void ObjectManager::AddObject(Object* newObject)
{
	//Make sure the object isn't already added to the scene graph.
	bool alreadyAdded = false;
	for (Object* o : scene)
	{
		if (o->GetId() == newObject->GetId())
		{
			printf("Game object with id: %d already exists in scene graph.", newObject->GetId());
			alreadyAdded = true;
		}
	}
	
	if (!alreadyAdded)
	{
		scene.push_back(newObject);
		printf("Object %d added to manager. \n", newObject->GetId());
	}
}

/*bool ObjectManager::RemoveObject(Object* object)
{

	for (Object o : *object->GetChildren())
	{
		RemoveObject(&o);
	}

	auto it = std::find(scene.begin(), scene.end(), *object);

	//printf("%d\n", it - scene.begin());

	if (it == scene.end())
	{
		printf("This is a fail");
		return false;
	}

	scene.erase(it);
	return true;
}*/



void ObjectManager::Update(const float& dt)
{
	//printf("Object manager is trying to update...\n");
	// replace this later
	// children could update before parent
	for (Object* o : scene)
	{
		o->Update(dt);
	}

	//for (std::vector<Object*>::iterator it = scene.begin(); it != scene.end(); ++it)
	//{
	//	(*it)->Update();
	//}
}
