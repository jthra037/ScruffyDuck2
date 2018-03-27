#pragma once
#include <vector>
#include <map>
#include "Utilities.h"

class RigidBody2D;

class Physics
{
public:
	static std::vector<RigidBody2D*> RegisteredBodies;

	struct CollisionPair
	{
		RigidBody2D* bodyA;
		RigidBody2D* bodyB;

		CollisionPair(RigidBody2D* a, RigidBody2D* b) :
			bodyA(a),
			bodyB(b)
		{
		}

		CollisionPair()
		{}
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

inline bool operator<(const Physics::CollisionPair &lhs, const Physics::CollisionPair &rhs)
{
	return lhs.bodyA != rhs.bodyA || lhs.bodyB != rhs.bodyB || lhs.bodyA != rhs.bodyB;
}