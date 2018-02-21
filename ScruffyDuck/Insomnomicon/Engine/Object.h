#pragma once
#include "Component.h"
#include <vector>

class Object
{
public:
	Object();
	Object(Object*);
	bool operator== (const  Object&);
	void SetParent(Object*);
	void Update();
	void AttachComponent(Component*);
	void RemoveComponent(Component*);
	std::vector<Object*>* GetChildren();
	std::vector<Component*>* GetComponents();

private:
	void AddChild(Object*);
	Object* parent;
	std::vector<Object*> children;
	std::vector<Component*> components;
	int id;
};