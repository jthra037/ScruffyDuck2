#pragma once
#include <vector>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	//~ObjectManager();
	void Update();
	void AddObject(Object&);
	std::vector<Object> scene;

};
