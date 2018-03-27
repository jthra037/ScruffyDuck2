#include "RigidBody2D.h"
#include "Object.h"

RigidBody2D::RigidBody2D(Object* o, float mass) : 
	Component(o),
	Mass(mass)
{
}

RigidBody2D::~RigidBody2D()
{
}

void RigidBody2D::Update(const float& dt)
{
	// nothing here for now i guess
}

void RigidBody2D::Integrate(const float& dt)
{
	//printf("dt is %f", dt);

	if (Mass == 0.0f)
	{
		return;
	}

	NSimp::Vec2<float> F;
	for each (NSimp::Vec2<float> force in forces)
	{
		F += force;
	}

	for each (NSimp::Vec2<float> impulse in impulses)
	{
		F += impulse;
	}

	if (IsAffectedByGravity)
	{
		// invert gravity in y as well
		F += NSimp::Vec2<float>(gravity);
	}

	impulses.clear();

	accel = F / Mass;
	velocity += accel * 0.01;
	position += velocity * 1;


	GetOwner()->transform->move(velocity.x, -velocity.y);
	printf("Owner position is:%f, %f\n", GetOwner()->transform->getPosition().x,
		GetOwner()->transform->getPosition().y);
}