#pragma once
#include <vector>
#include <algorithm>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	//~ObjectManager();
	void Update();
	void AddObject(Object&);
	void RemoveObject(Object&);
	std::vector<Object> scene;
};
