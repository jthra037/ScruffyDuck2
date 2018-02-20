#pragma once
#include <vector>

class Object
{
public:
	Object();
	Object(Object*);
	bool operator== (const  Object&);
	void SetParent(Object*);
	void Update();
	std::vector<Object>* GetChildren();
private:
	void AddChild(Object*);
	Object* parent;
	std::vector<Object> children;
	int id;
};