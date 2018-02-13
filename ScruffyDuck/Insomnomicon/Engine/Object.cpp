#include "Object.h"

static int _id = 0;

Object::Object(Object* thisParent = nullptr)
{
	parent = nullptr;
	id = _id++;
	children = std::vector<Object>();
}

void Object::Update()
{
	printf("%d is updating...", id);
}