#include "MenuScene.h"
#include "GalagaScene.h"
#include "Engine.h"
#include "SceneManager.h"

MenuScene::MenuScene(const char* newName) : Scene(newName)
{
	BuildScene();
}

void MenuScene::BuildScene()
{
	Object* obj0 = new Object();
	obj0->AttachComponent(new SpriteRenderer(obj0, "Assets/Textures/PlayTemp.png"));
	
	ButtonComp* menuButton = new ButtonComp(obj0);
	menuButton->AddFunctor([]() {
		Scene* mainMenu = Engine::_sceneManager->GetScene("Main");
		if (mainMenu != nullptr)
		{
			mainMenu = new GalagaScene("Main");
			Engine::_sceneManager->ActiveScene = mainMenu;
		}
	});

	obj0->AttachComponent(menuButton);

	obj0->transform->move(200, 10);
	obj0->transform->scale(0.5f, 0.8f);

	_objectManager->AddObject(obj0);
}