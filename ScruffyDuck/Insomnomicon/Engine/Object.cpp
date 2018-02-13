#include "Object.h"

static int _id = 0;

Object::Object()
{
	parent = nullptr;
	id = _id++;
	children = std::vector<Object>();
}

Object::Object(Object* thisParent)
{
	parent = thisParent;
	id = _id++;
	children = std::vector<Object>();
}

void Object::SetParent(Object* newParent)
{
	parent = newParent;
}

void Object::Update()
{
	printf("%d is updating...\n", id);
}