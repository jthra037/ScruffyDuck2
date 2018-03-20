#pragma once
#include "Object.h"
#include "Component.h"
#include <SFML\System\Vector2.hpp>

class RigidBody2D :
	public Component
{
public:
	RigidBody2D();
	RigidBody2D(Object);
	~RigidBody2D();

	float mass;
	sf::Vector2<float> velocity;
protected:
	Object gameObject;
};

