#include "GalagaScene.h"

GalagaScene::GalagaScene()
{
	BuildScene();
}

void GalagaScene::Update(const float& dt)
{
	_objectManager->Update();
}

void GalagaScene::BuildScene()
{
	Object* obj0 = new Object();
	obj0->AttachComponent(new SpriteRenderer(obj0, "Assets/Textures/PlayTemp.png"));

	Object* obj1 = new Object();
	obj1->AttachComponent(new SpriteRenderer(obj0, "Assets/Textures/PlayTemp.png"));
	obj1->AddParent(obj0);
	obj0->transform->move(0, 10);
	obj1->transform->move(10, 100);

	_objectManager->AddObject(obj1);
	_objectManager->AddObject(obj0);
}