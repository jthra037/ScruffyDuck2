#include "Object.h"

Object::Object(std::string newName = "Object", 
	Object* thisParent = nullptr)
{
	name = newName;
	parent = nullptr;
	children = std::vector<Object>();
}

void Object::Update()
{
	printf("%s is updating...", name);

	for(Object o : children)
	{
		o.Update();
	}
}