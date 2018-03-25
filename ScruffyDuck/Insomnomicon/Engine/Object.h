#pragma once
#include "Component.h"
#include "OTransform.h"
#include <vector>

class Object
{
public:
	Object();
	Object(Object*);
	bool operator== (const Object&);
	void Update();
	void AddParent(Object*);
	void AddChild(Object*);
	void AttachComponent(Component*);
	void RemoveComponent(Component*);

	OTransform* transform;
	sf::Transform worldTransform;

	//Getters.
	int GetId();
	Object* GetParent();
	std::vector<Object*>* GetChildren();
	std::vector<Component*>* GetComponents();

private:
	int id;
	Object* parent;
	std::vector<Object*> children;
	std::vector<Component*> components;
};