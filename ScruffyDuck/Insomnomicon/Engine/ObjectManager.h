#pragma once
#include <vector>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void Update();
	void AddObject();
	void AddObject(Object object);

private:
	std::vector<Object> scene;
};
