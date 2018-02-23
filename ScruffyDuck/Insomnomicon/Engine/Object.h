#pragma once
#include "Component.h"
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