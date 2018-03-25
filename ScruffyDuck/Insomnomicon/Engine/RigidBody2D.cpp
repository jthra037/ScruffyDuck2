#include "RigidBody2D.h"

RigidBody2D::RigidBody2D(Object* o) : Component(o)
{
}

RigidBody2D::~RigidBody2D()
{
}

void RigidBody2D::Update(const float& dt)
{
	printf("dt is %f", dt);

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
	impulses.clear();

	accel = F / Mass;
	velocity += accel * dt;
	position += velocity * dt;
}