#pragma once
#include "components.h"
#include "vector.h"
#include <reactphysics3d/reactphysics3d.h>

using namespace reactphysics3d;



class transformComponent : public component
{
public:
	
	//physics
	Vector3 p1;

	Quaternion orientation;
	Transform transform;
	RigidBody* rigidBody;
	BoxShape* boxShape;


	transformComponent()
	{
	}

	transformComponent(float x, float y)
	{
	}

	void init() override
	{
	}
	void update() override
	{
	}
	
	transformComponent(PhysicsCommon* physics, PhysicsWorld* world, float x, float y)
	{
		orientation = Quaternion::identity();

		transform = Transform(Vector3(x, y, 0), orientation);
		rigidBody = world->createRigidBody(transform);
		//i choose the box shape because the sprite will be a box shape as well with the size of 32-32
		boxShape = physics->createBoxShape(Vector3(32, 32, 1));
		rigidBody->addCollider(boxShape, Transform::identity());
		//the gravity is false so the body wont fall from the world
		rigidBody->enableGravity(false);
	}

private:
	

};