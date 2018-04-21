#include "Scene.h"
#include "Physics.h"
Scene::Scene()
{
	_objectManager = new ObjectManager();
	runtime = timer.restart();
}

void Scene::Update(const float& dt)
{
	sf::Time newRuntime = timer.getElapsedTime();
	float delta = newRuntime.asSeconds() - runtime.asSeconds();
	runtime = newRuntime;

	_objectManager->Update(dt);
	Physics::Update(dt);
}
