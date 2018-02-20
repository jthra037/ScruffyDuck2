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
	SetParent(thisParent);
	id = _id++;
	children = std::vector<Object>();
}

bool Object::operator==(const Object& object)
{
	//printf("%d : %d\n", id, object.id);
	return id == object.id;
}

void Object::SetParent(Object* newParent)
{
	parent = newParent;
	parent->AddChild(this);
}

void Object::Update()
{
	printf("%d is updating\n", id);
}

std::vector<Object>* Object::GetChildren()
{
	return &children;
}

void Object::AddChild(Object* object)
{
	children.push_back(*object);
}
