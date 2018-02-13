#pragma once
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	scene = std::vector<Object>();
}

void ObjectManager::AddObject(Object& newObject)
{
	scene.push_back(newObject);
}

void ObjectManager::RemoveObject(Object& object)
{
	for (auto it = scene.begin(); it != scene.end; it++)
	{
		if (*it == object)
		{

		}
	}
}



void ObjectManager::Update()
{
	printf("Object manager is trying to update...\n");
	for (Object o : scene)
	{
		o.Update();
	}
}
