#pragma once
#include "Component.h"
#include <functional>
#include <vector>
#include <SFML\Window\Mouse.hpp>
#include "SFML\Graphics\Transform.hpp"

typedef void(*Functor)(void);

class ButtonComp :
	public Component
{
public:
	ButtonComp(Object*);
	~ButtonComp();

	void OnClicked();
	void Update(const float&);
	void AddFunctor(Functor);

	sf::Transform localTransform;
private:
	std::vector<Functor> functorList;

};

