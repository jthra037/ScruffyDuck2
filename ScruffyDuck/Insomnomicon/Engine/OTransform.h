#pragma once
#include <SFML\Graphics\Transformable.hpp>

class Object;

class OTransform : public sf::Transformable
{
public:
	OTransform(Object*);
	Object* GetOwner();
private:
	Object* owner;
};