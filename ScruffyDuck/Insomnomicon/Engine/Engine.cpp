#include "Engine.h"
#include <iostream>
#include <cassert>

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

	Object* obj1 = new Object();
	Object* obj2 = new Object();

	Component* comp1 = new Component();
	obj1->AttachComponent(comp1);
	obj2->AttachComponent(new Component());
	obj1->AttachComponent(new Component());
	
	_objectManager->AddObject(obj1);
	_objectManager->AddObject(obj2);

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
	}

	_objectManager->Update();
	_mainWindow->clear();
	_mainWindow->display();
}
