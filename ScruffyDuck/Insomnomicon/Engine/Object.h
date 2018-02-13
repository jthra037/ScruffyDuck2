#pragma once
#include <vector>

class Object
{
public:
	Object();
	Object(Object*);
	void SetParent(Object*);
	void Update();
private:
	Object* parent;
	std::vector<Object> children;
	int id;
};