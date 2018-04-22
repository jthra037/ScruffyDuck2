#include "GalagaScene.h"
#include "Engine.h"
#include "SceneManager.h"

GalagaScene::GalagaScene(const char* newName) : Scene(newName)
{
	BuildScene();
}

void GalagaScene::BuildScene()
{
	Object* obj0 = new Object();
	obj0->AttachComponent(new SpriteRenderer(obj0, "Assets/Textures/PlayTemp.png"));
	
	ButtonComp* menuButton = new ButtonComp(obj0);
	menuButton->AddFunctor([]() {
		Scene* mainMenu = Engine::_sceneManager->GetScene("Menu");
		if (mainMenu != nullptr)
		{
			Engine::_sceneManager->ActiveScene = mainMenu;
		}
	});

	obj0->AttachComponent(menuButton);

	Object* obj1 = new Object();
	obj1->AttachComponent(new SpriteRenderer(obj1, "Assets/Textures/PlayTemp.png"));
	obj1->AttachComponent(new RigidBody2D(obj1));
	obj1->AddParent(obj0);
	obj0->transform->move(0, 10);
	obj1->transform->move(10, 100);
	obj0->transform->scale(0.5f, 0.8f);

	_objectManager->AddObject(obj1);
	_objectManager->AddObject(obj0);
}