#include "Object.h"

static int _objid = 0;

Object::Object()
{
	parent = nullptr;
	id = _objid++;
	children = std::vector<Object*>();
	components = std::vector<Component*>();
	transform = new OTransform(this);

	printf("Created an object with id: %d \n", id);
}

Object::Object(Object* thisParent)
{
	AddParent(thisParent);
	id = _objid++;
	children = std::vector<Object*>();
	components = std::vector<Component*>();
	transform = new OTransform(this);

	printf("Created an object with id: %d, which is childed to object %d. \n", id, thisParent->GetId());
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

void Object::Update()
{
	//printf("Object %d is updating. \n", id);
	for (Component* c : components)
	{
		c->Update();
	}
}

void Object::AddChild(Object* object)
{
	children.push_back(object);
}


void Object::AttachComponent(Component* comp)
{
	comp->SetOwner(this);
	components.push_back(comp);

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

std::vector<Component*>* Object::GetComponents()
{
	return nullptr;
}

#pragma endregion
