#include "Engine.h"
#include <iostream>

Engine::GameState Engine::_gameState = Engine::Playing;
ObjectManager* Engine::_objectManager;
sf::RenderWindow* Engine::_mainWindow;

void Engine::Start()
{
	_gameState = Engine::Playing;
	if (_gameState == Uninitialized)
		return;

	_mainWindow->create(sf::VideoMode(1024, 768, 32), "GameName Here");
	_gameState = Engine::Playing;
	_objectManager = new ObjectManager();

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow->close();
}

void Engine::Initialize()
{
	puts("Only thing we're init'ing is _mainWindow right now");
	_mainWindow = new sf::RenderWindow();
}

bool Engine::IsExiting()
{
	return _gameState == GameState::Exiting;
}

void Engine::GameLoop()
{
	sf::Event event;
	while (_mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_gameState = GameState::Exiting;
		}
		_objectManager->Update();
	}

	_mainWindow->clear();
	_mainWindow->display();
}
