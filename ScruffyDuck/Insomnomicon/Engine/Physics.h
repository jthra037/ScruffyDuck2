#pragma once
#include <vector>
#include <map>
#include "Utilities.h"
#include "RigidBody2D.h"

class Physics
{
public:
	static std::vector<RigidBody2D> RegisteredBodies;

	struct CollisionPair
	{
		RigidBody2D& bodyA;
		RigidBody2D& bodyB;
	};

	struct CollisionInfo
	{
		NSimp::Vec2<float> collisionNormal;
		float penetration;
	};

	static void Update(const float& dt = 0.01f);

private:
	static std::map<CollisionPair, CollisionInfo> collisions;
	
	static void CheckCollisions();
	static void ResolveCollisions();
	static void PositionalCorrection(CollisionPair&);
	static void IntegrateBodies(const float& dt);
};

