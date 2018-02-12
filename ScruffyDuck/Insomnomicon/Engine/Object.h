#pragma once
#include <vector>

class Object
{
public: 
	Object(std::string, Object*);
	virtual void Update() = 0;
private:
	std::string name;
	Object* parent;
	std::vector<Object> children;
};