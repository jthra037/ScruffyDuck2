#pragma once
#include "Component.h"
#include "RigidBody2D.h"

class Collider :
	public Component
{
public:
	Collider(Object*);
	~Collider();
	
	RigidBody2D attachedRigidBody2D;
	bool enabled;
	bool isTrigger;
};

