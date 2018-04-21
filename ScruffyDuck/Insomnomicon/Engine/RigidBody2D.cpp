#include "RigidBody2D.h"
#include "Object.h"
#include "Physics.h"

RigidBody2D::RigidBody2D(Object* o, float mass) : 
	Component(o),
	Mass(mass)
{
	Physics::RegisteredBodies.push_back(this);
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
		F += NSimp::Vec2<float>(Physics::Gravity);
	}

	impulses.clear();

	accel = F / Mass;
	velocity += accel * dt;
	position += velocity * dt;


	GetOwner()->transform->move(velocity.x, -velocity.y);
	printf("Owner position is:%f, %f\n", GetOwner()->transform->getPosition().x,
		GetOwner()->transform->getPosition().y);
}