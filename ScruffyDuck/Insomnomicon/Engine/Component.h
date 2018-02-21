#pragma once
#include <stdio.h>

class Object;

class Component
{
public:
	Component();
	bool operator== (const Component&);
	void Update();
	void SetOwner(Object*);
	Object GetOwner();

private:
	Object* owner;
	int id;
};