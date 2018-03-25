#pragma once
#include "Collider.h"
#include "SFML\System\Vector2.hpp"

class BoxCollider2D :
	public Collider
{
public:
	BoxCollider2D(Object*);
	~BoxCollider2D();

	sf::Vector2<float> size;
};

