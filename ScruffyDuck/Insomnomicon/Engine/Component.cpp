#include "Component.h"
#include "Object.h"

static int _compid;

Component::Component()
{
	owner = nullptr;
	id = _compid++;

	printf("Created a component with id: %d \n", id);
}

bool Component::operator==(const Component& comp)
{
	return id == comp.id;
}

void Component::SetOwner(Object* own)
{
	owner = own;
}

Object Component::GetOwner()
{
	return owner;
}

int Component::GetId()
{
	return id;
}