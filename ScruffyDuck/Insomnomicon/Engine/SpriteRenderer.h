#pragma once
#include "Component.h"
#include <SFML\Graphics.hpp>

class SpriteRenderer :
	public Component
{
public:
	SpriteRenderer(Object*);
	SpriteRenderer(Object*, const char*);
	SpriteRenderer(Object*, const sf::Texture&);
	~SpriteRenderer();
	sf::Sprite _sprite;

	void LoadTexture(const char*);

	void Update(const float&);

private:
	sf::Texture _tex;
};

