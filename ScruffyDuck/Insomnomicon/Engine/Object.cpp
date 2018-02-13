#include "Object.h"

static int _id = 0;

Object::Object(std::string newName = "Object", 
	Object* thisParent = nullptr)
{
	name = newName;
	parent = nullptr;
	id = _id++;
	children = std::vector<Object>();
}

void Object::Update()
{
	printf("%d is updating...", id);
}