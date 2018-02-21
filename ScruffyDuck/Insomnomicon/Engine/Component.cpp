#include "Component.h"
#include "Object.h"

static int _compid;

Component::Component()
{
	owner = nullptr;
	id = _compid++;
}

bool Component::operator==(const Component& comp)
{
	//printf("%d : %d\n", id, object.id);
	return id == comp.id;
}

void Component::Update()
{
	printf("%d is updating\n", id);
}

void Component::SetOwner(Object* own)
{
	owner = own;
}

Object Component::GetOwner()
{
	return owner;
}