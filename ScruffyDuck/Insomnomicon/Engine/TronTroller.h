#pragma once
#include "Component.h"
#include "SFML\Graphics.hpp"
#include <vector>

class TronTroller :
	public Component
{
public:
	enum Direction {LEFT, UP, RIGHT, DOWN};

	Direction facing;

	int speed = 2;
	int thickness = 10;
	bool isDead = false;

	std::vector<sf::RectangleShape*> body;
	sf::Vector2f head;
	sf::Color color;


	TronTroller(Object*);
	TronTroller(Object*, sf::Vector2f);
	~TronTroller();

	void Update(const float&);

private:
	void Move(const float&);
	void PollInputs();
	void CheckCollisions();
	void RenderSelf();
};

