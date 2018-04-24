#pragma once
#include "Component.h"
#include "OTransform.h"
#include <vector>
#include <unordered_map>
#include <typeindex>

class Object
{
public:
	Object();
	Object(Object*);
	~Object();
	bool operator== (const Object&);
	void Update(const float& = 0);
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
	std::unordered_map<std::type_index, Component*>* GetComponents();

private:
	int id;
	Object* parent;
	std::vector<Object*> children;
	std::unordered_map<std::type_index, Component*> components;
};