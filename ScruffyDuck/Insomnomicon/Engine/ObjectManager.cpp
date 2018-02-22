#pragma once
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	scene = std::vector<Object>();
}

void ObjectManager::AddObject(Object* newObject)
{
	scene.push_back(*newObject);

	printf("Object %d added to manager. It will update. \n", newObject->GetId());
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



void ObjectManager::Update()
{
	//printf("Object manager is trying to update...\n");
	for (Object o : scene)
	{
		o.Update();
	}
}
