#include "TronTroller.h"
#include "Object.h"
#include "Engine.h"
#include "SFML\Window\Keyboard.hpp"

TronTroller::TronTroller(Object* o) : Component(o)
{
	facing = TronTroller::DOWN;
}

TronTroller::TronTroller(Object* o, sf::Vector2f _head) : Component(o)
{
	head = _head;
	facing = TronTroller::DOWN;

	color = sf::Color::White;

	sf::RectangleShape rs = sf::RectangleShape(sf::Vector2f(0, 0));
	rs.setOrigin(sf::Vector2f(0.5f, 0));
	rs.setPosition(head);
	rs.setSize(sf::Vector2f(thickness, 1));

	body.push_back(&rs);
}

TronTroller::~TronTroller()
{
}

void TronTroller::Update(const float& dt)
{
	if (isDead)
	{
		return;
	}

	PollInputs();
	//Move(dt);
	CheckCollisions();

	for each (sf::RectangleShape* piece in body)
	{
		Engine::GetWindow().draw(*piece);
	}
}

void TronTroller::Move(const float& dt)
{
	switch (facing)
	{
	case TronTroller::LEFT:
		head.x -= speed;
		break;
	case TronTroller::UP:
		head.y -= speed;
		break;
	case TronTroller::RIGHT:
		head.x += speed;
		break;
	case TronTroller::DOWN:
		head.y += speed;
		break;
	default:
		break;
	}

	sf::RectangleShape* tail = body.back();

	sf::Vector2f size = head - tail->getPosition();
	size.x = size.x == 0 ? thickness : size.x;
	size.y = size.y == 0 ? thickness : size.y;

	//tail->setSize(size);
}

void TronTroller::PollInputs()
{

}

void TronTroller::CheckCollisions()
{
}

void TronTroller::RenderSelf()
{
}
