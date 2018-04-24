#include "Object.h"
#include <type_traits>

static int _objid = 0;

Object::Object()
{
	parent = nullptr;
	id = _objid++;
	children = std::vector<Object*>();
	components = std::unordered_map<std::type_index, Component*>();
	transform = new OTransform(this);

	printf("Created an object with id: %d \n", id);
}

Object::Object(Object* thisParent)
{
	AddParent(thisParent);
	id = _objid++;
	children = std::vector<Object*>();
	components = std::unordered_map<std::type_index, Component*>();
	transform = new OTransform(this);

	printf("Created an object with id: %d, which is childed to object %d. \n", id, thisParent->GetId());
}

Object::~Object()
{
	//if (transform != nullptr)
	//{
	//	delete transform;
	//}

	for each (auto p in components)
	{
		delete p.second;
	}

	for each (Object* o in children)
	{
		delete o;
	}
}

bool Object::operator==(const Object& object)
{
	//printf("%d : %d\n", id, object.id);
	return id == object.id;
}

void Object::AddParent(Object* newParent)
{
	parent = newParent;
	parent->AddChild(this);
}

void Object::Update(const float& dt)
{
	//printf("Object %d is updating. \n", id);
	// make sure to actually apply the transforms
	sf::Transform pt = parent != nullptr ?
		parent->worldTransform :
		sf::Transform::Identity;

	sf::Transform t = transform->getTransform();
	worldTransform = t.combine(pt);

	for (auto it = components.begin(); it != components.end(); ++it)
	{
		it->second->Update(dt);
	}
}

void Object::AddChild(Object* object)
{
	children.push_back(object);
}


void Object::AttachComponent(Component* comp)
{
	comp->SetOwner(this);
	components[typeid(*comp)] = comp;

	printf("Attached a component to object with id: %d \n", id);
}

void Object::RemoveComponent(Component *)
{

}

#pragma region Getters

int Object::GetId()
{
	return id;
}

Object* Object::GetParent()
{
	return parent;
}

std::vector<Object*>* Object::GetChildren()
{
	return &children;
}

std::unordered_map<std::type_index, Component*>* Object::GetComponents()
{
	return &components;
}

#pragma endregion
