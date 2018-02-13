#pragma once
#include <vector>

class Object
{
public: 
	Object(std::string, Object*);
	void Update();
private:
	std::string name;
	Object* parent;
	std::vector<Object> children;
	int id;
};