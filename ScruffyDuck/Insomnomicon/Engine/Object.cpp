#include "Object.h"

static int _objid = 0;

Object::Object()
{
	parent = nullptr;
	id = _objid++;
	children = std::vector<Object*>();
	components = std::vector<Component*>();
}

Object::Object(Object* thisParent)
{
	SetParent(thisParent);
	id = _objid++;
	children = std::vector<Object*>();
	components = std::vector<Component*>();
}

bool Object::operator==(const Object& object)
{
	//printf("%d : %d\n", id, object.id);
	return id == object.id;
}

void Object::SetParent(Object* newParent)
{
	parent = newParent;
	parent->AddChild(this);
}

void Object::Update()
{
	//printf("%d is updating\n", id);
	for (Component* c : components)
	{
		c->Update();
	}
}

std::vector<Object*>* Object::GetChildren()
{
	return &children;
}


void Object::AddChild(Object* object)
{
	children.push_back(object);
}


void Object::AttachComponent(Component* comp)
{
	//comp->SetOwner(this);
	components.push_back(comp);
}

void Object::RemoveComponent(Component *)
{
}

std::vector<Component*>* Object::GetComponents()
{
	return nullptr;
}
