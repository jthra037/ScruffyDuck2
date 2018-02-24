#include "OTransform.h"
#include "Object.h"

OTransform::OTransform(Object* newOwner)
{
	owner = newOwner;
}

Object* OTransform::GetOwner()
{
	return owner;
}