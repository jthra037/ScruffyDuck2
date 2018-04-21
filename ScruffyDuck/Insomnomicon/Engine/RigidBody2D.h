#pragma once
#include "Component.h"
#include "Utilities.h"
#include <vector>

class RigidBody2D :
	public Component
{
public:
	RigidBody2D(Object*, float mass = 1);
	~RigidBody2D();

	float Mass;
	bool IsAffectedByGravity = true;

	void AddForce(const NSimp::Vec2<float>& force) { forces.push_back(force); }
	void AddImpulse(const NSimp::Vec2<float>& impulse) { impulses.push_back(impulse); }
	//void Update(const float dt);
	void Update(const float&);
	void Integrate(const float&);

	const NSimp::Vec2<float>& GetVelocity() { return velocity; }
	const NSimp::Vec2<float>& GetPosition() { return position; }
	const NSimp::Vec2<float>& GetAccel() { return accel; }

	void SetVelocity(const NSimp::Vec2<float>& newVelocity) { velocity = newVelocity; }
	void SetAccel(const NSimp::Vec2<float>& newAccel) { accel= newAccel; }

	struct AABB
	{
		NSimp::Vec2<float> bLeft;
		NSimp::Vec2<float> tRight;

		AABB(){}

		AABB(const float& blx,
			const float& bly, 
			const float& rtx, 
			const float& rty)
		{
			bLeft = NSimp::Vec2<float>(blx, bly);
			tRight = NSimp::Vec2<float>(rtx, rty);
		}

		AABB(const NSimp::Vec2<float>& bottomLeft,
			const NSimp::Vec2<float>& topRight)
		{
			bLeft = bottomLeft;
			tRight = topRight;
		}
	};

	AABB aabb;
protected:
	Object* gameObject;
	NSimp::Vec2<float> velocity, position, accel;
	std::vector<NSimp::Vec2<float>> forces, impulses;
	
	//NSimp::Vec3<float> gravity = NSimp::Vec3<float>(0, -9.8f, 0);
};

