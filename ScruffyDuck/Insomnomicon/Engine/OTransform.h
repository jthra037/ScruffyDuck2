#pragma once
#include <SFML\Graphics\Transformable.hpp>

class Object;

// This seriously locks us down to SFML
class OTransform : public sf::Transformable
{
public:
	OTransform(Object*);
	~OTransform();
	Object* GetOwner();
private:
	Object* owner;
	// We may need a local component here also
};