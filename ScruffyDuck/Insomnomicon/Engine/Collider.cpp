#include "Collider.h"



Collider::Collider(Object* o) :
	Component(o),
	attachedRigidBody2D(o)
{
}


Collider::~Collider()
{
}
