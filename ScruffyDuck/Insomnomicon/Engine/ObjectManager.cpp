#pragma once
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	scene = std::vector<Object>();
}

void ObjectManager::AddObject(Object newObject)
{
	scene.push_back(newObject);
}

Object ObjectManager::Update(Object object)
{
	object.Update();
	return object;
}
