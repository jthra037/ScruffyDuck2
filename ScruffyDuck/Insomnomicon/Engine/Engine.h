#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class SceneManager;
class ObjectManager;

class GalagaScene;

class Engine
{
public:
	static void Start();
	static void Initialize();
	static sf::RenderWindow& GetWindow();
	static SceneManager* _sceneManager;

private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState { Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting };

	static sf::RenderWindow* _mainWindow;
	static GameState _gameState;
	static ObjectManager* _objectManager;
};