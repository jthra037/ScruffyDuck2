#pragma once
//#include "Object.h"
#include <stdio.h>

class Component
{
public:
	Component();
	bool operator== (const Component&);
	void Update();
//	void SetOwner(Object*);
//	Object GetOwner();
//
private:
//	Object* owner;
	int id;
};