#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer(Object* o) : Component(o)
{
	
}

SpriteRenderer::SpriteRenderer(Object* o, const sf::Texture& tex) : Component(o)
{
	_tex = tex;
	_sprite.setTexture(_tex);
}
SpriteRenderer::SpriteRenderer(Object* o, const char* path) : Component(o)
{
	LoadTexture(path);
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Update(const float& dt)
{
	Engine::GetWindow().draw(_sprite, GetOwner()->worldTransform);
}

void SpriteRenderer::LoadTexture(const char* path)
{
	if (_tex.loadFromFile(path))
	{
		_sprite.setTexture(_tex);
	}
	else
	{
		printf("Failed to load splash screen.\n\n");
	}
}

