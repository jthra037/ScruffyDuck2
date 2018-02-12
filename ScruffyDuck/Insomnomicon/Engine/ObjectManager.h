#pragma once
#include <vector>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	//~ObjectManager();
	Object Update(Object);
	void AddObject(Object);
	std::vector<Object> scene;

};
