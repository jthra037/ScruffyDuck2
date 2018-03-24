#pragma once
#include "Object.h"
#include "Component.h"
#include "Utilities.h"
#include <vector>

class RigidBody2D :
	public Component
{
public:
	RigidBody2D();
	RigidBody2D(Object*);
	~RigidBody2D();

	float Mass;

	void AddForce(const NSimp::Vec2<float>& force) { forces.push_back(force); }
	void AddImpulse(const NSimp::Vec2<float>& impulse) { impulses.push_back(impulse); }
	void OnUpdate(const float dt);

	const NSimp::Vec2<float>& GetVelocity() { return velocity; }
	const NSimp::Vec2<float>& GetPosition() { return position; }
	const NSimp::Vec2<float>& GetAccel() { return accel; }

	void SetVelocity(const NSimp::Vec2<float>& newVelocity) { velocity = newVelocity; }
	void SetAccel(const NSimp::Vec2<float>& newAccel) { accel= newAccel; }
protected:
	Object* gameObject;
	NSimp::Vec2<float> velocity, position, accel;
	std::vector<NSimp::Vec2<float>> forces, impulses;
};

