#include "Physics.h"

std::map<Physics::CollisionPair, Physics::CollisionInfo> Physics::collisions;
std::vector<RigidBody2D*> Physics::RegisteredBodies;

void Physics::Update(const float& dt)
{
	CheckCollisions();
	ResolveCollisions();
	IntegrateBodies(dt);
}

void Physics::CheckCollisions()
{
	for (auto itA = RegisteredBodies.begin(); itA != RegisteredBodies.end(); ++itA)
	{
		for (auto itB = itA; itB != RegisteredBodies.end(); ++itB)
		{
			CollisionPair pair = CollisionPair(**itA , **itB);
			CollisionInfo info;
			
			NSimp::Vec2<float> dist = (*itB)->GetPosition() - (*itA)->GetPosition();
			NSimp::Vec2<float> halfSizeA = ((*itA)->aabb.tRight - (*itA)->aabb.bLeft) / 2;
			NSimp::Vec2<float> halfSizeB = ((*itB)->aabb.tRight - (*itB)->aabb.bLeft) / 2;
			
			NSimp::Vec2<float> gap(abs(dist.x), abs(dist.y));

			// Seperating Axis Theorem Test
			if (gap.x < 0 && gap.y < 0)
			{
				printf("We got a collision here!\n");
				if (collisions.find(pair) != collisions.end())
				{
					collisions.erase(pair);
				}

				if (gap.x > gap.y)
				{
					if (dist.x > 0)
					{
						info.collisionNormal = NSimp::Vec2<float>(1, 0);
					}
					else
					{
						info.collisionNormal = NSimp::Vec2<float>(-1, 0);
					}
					info.penetration = gap.x;
				}
				else
				{
					if (dist.y > 0)
					{
						info.collisionNormal = NSimp::Vec2<float>(0, 1);
					}
					else
					{
						info.collisionNormal = NSimp::Vec2<float>(0, -1);
					}
					info.penetration = gap.y;
				}
				collisions.insert(std::pair<CollisionPair, CollisionInfo>(pair, info));
			}
			else if (collisions.find(pair) != collisions.end())
			{
				collisions.erase(pair);
			}
		}
	}
}

void Physics::ResolveCollisions()
{

}

void Physics::IntegrateBodies(const float& dt)
{

}

void Physics::PositionalCorrection(CollisionPair& c)
{

}
