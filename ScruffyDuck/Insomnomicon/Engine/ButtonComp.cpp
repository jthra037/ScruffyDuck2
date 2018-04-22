#include "ButtonComp.h"
#include "Engine.h"
#include "Object.h"
#include "SpriteRenderer.h"

#include "SFML\Graphics\Rect.hpp"

ButtonComp::ButtonComp(Object* o) :
	Component(o)
{
	localTransform = sf::Transform::Identity;
}

ButtonComp::~ButtonComp()
{
}

void ButtonComp::OnClicked()
{
	for each (Functor functor in functorList)
	{
		functor();
	}
}

void ButtonComp::AddFunctor(Functor f)
{
	functorList.push_back(f);
}

void ButtonComp::Update(const float& dt)
{
	if (sf::Mouse::isButtonPressed(
		sf::Mouse::Button::Left))
	{
		printf("Mouse button was clicked!\n");

		sf::Vector2i localMousePosition = 
			sf::Mouse::getPosition(Engine::GetWindow());

		printf("Mouse found at: %i, %i\n", localMousePosition.x, localMousePosition.y);

		//sf::Transform combinedTransform = GetOwner()->worldTransform * localTransform;
		//sf::Rect<float> buttonRect = sf::Rect<float>(0, 0, 1, 1);
		//buttonRect = combinedTransform.transformRect(buttonRect);

		sf::FloatRect buttonRect = GetOwner()->GetComponent<SpriteRenderer>()->_sprite.getLocalBounds();
		
		printf("Checking inside Rect(%f, %f, %f, %f)\n", buttonRect.left, buttonRect.top, buttonRect.width, buttonRect.height);
		
		if (localMousePosition.x > buttonRect.left &&
			localMousePosition.x < buttonRect.left + buttonRect.width &&
			localMousePosition.y > buttonRect.top &&
			localMousePosition.y < buttonRect.top + buttonRect.height)
		{
			printf("Button was clicked and should be doing something soon...");
			OnClicked();
		}
	}
}
