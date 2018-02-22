#pragma once
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	scene = std::vector<Object*>();
}

void ObjectManager::AddObject(Object* newObject)
{
	//Add a standalone object.
	if (newObject->GetChildren()->size() <= 0 && newObject->GetParent() == nullptr)
	{
		scene.push_back(newObject);
		printf("Standalone object, object %d added to manager. It will update. \n", newObject->GetId());
	}
	//Object has a parent, add parent if not already in manager.
	else if (newObject->GetChildren()->size() <= 0 && newObject->GetParent() != nullptr)
	{
		printf("Object %d has parent, checking for parent in graph... \n", newObject->GetId());
		
		bool addParent = true;
		Object* p = newObject->GetParent();
		for (Object o : scene)
		{
			if (o.GetId() == p->GetId())
			{
				printf("Parent already exists in the graph. \n");
				addParent = false;
				break;
			}
		}

		if (addParent)
		{
			printf("Parent not found in graph. Adding parent, id: %d. \n", p->GetId());
			scene.push_back(p);
		}

		scene.push_back(newObject);
		printf("Object with parent but no children, object %d added to manager. It will update. \n", newObject->GetId());
	}
	//Object has children, add children if not already in manager.
	//Object has both parent and children, add any that aren't in manager.
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
