#pragma once
#include <vector>
#include <algorithm>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	void Update();
	void AddObject(Object*);
	std::vector<Object*> scene;
};
