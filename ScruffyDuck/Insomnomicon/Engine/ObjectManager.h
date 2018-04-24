#pragma once
#include <vector>
#include <algorithm>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void Update(const float& = 0);
	void AddObject(Object*);
	std::vector<Object*> scene;
};
