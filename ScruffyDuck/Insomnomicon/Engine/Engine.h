#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ObjectManager.h"
#include "Scene.h"

class Engine
{
public:
	static void Start();
	static void Initialize();
	static sf::RenderWindow& GetWindow();

private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState { Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting };

	static sf::RenderWindow* _mainWindow;
	static GameState _gameState;
	static ObjectManager* _objectManager;
	static Scene* _scene;
};

