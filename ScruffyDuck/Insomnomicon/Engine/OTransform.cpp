#include "OTransform.h"
#include "Object.h"

OTransform::OTransform(Object* newOwner)
{
	owner = newOwner;
}

OTransform::~OTransform()
{
}

Object* OTransform::GetOwner()
{
	return owner;
}