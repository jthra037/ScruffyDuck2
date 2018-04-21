#include "ButtonComp.h"

ButtonComp::ButtonComp(Object* o) :
	Component(o)
{
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
	functorList.insert(functorList.end, f);
}

void ButtonComp::Update(const float& dt)
{

}
