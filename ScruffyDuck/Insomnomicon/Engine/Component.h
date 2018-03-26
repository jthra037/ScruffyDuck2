#pragma once
#include <stdio.h>

class Object;

class Component
{
public:
	Component(Object*);
	bool operator== (const Component&);
	virtual void Update(const float& = 0) = 0;
	void SetOwner(Object*);
	
	Object* GetOwner();
	int GetId();

private:
	Object* owner;
	int id;
};