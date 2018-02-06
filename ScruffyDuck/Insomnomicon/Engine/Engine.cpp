#include "Engine.h"

void Engine::Start()
{
	if (_gameState == Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "GameName Here");
	_gameState = Engine::Playing;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

void Engine::Initialize()
{
	puts("Not actually doing init right now");
}

bool Engine::IsExiting()
{
	return false;
}

void Engine::GameLoop()
{
	while (_mainWindow.isOpen())
	{
		sf::Event event;
		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_mainWindow.close();
			}
		}

		_mainWindow.clear();
		_mainWindow.display();
	}
}
