#pragma once
#include "Game.h"
#include "ECS.h"
#include "components.h"

class KeyBoard : public component
{
public:
	transformComponent *transform;
	RigidBody* rigidbody;
	
	void init() override
	{
		transform = &entity->getComponent<transformComponent>();
		rigidbody = transform->rigidBody;
	}

	void update() override
	{
		
		if (Game::event.type == SDL_KEYDOWN)
		{

			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				// moving UP
				rigidbody->setLinearVelocity(Vector3(0, -100, 0));
				break;
			case SDLK_a:
				// moving left
				rigidbody->setLinearVelocity(Vector3(-100, 0, 0));
				
				break;
			case SDLK_s:
				// moving down
				rigidbody->setLinearVelocity(Vector3(0, 100, 0));
				break;
			case SDLK_d:
				//moving right
				rigidbody->setLinearVelocity(Vector3(100, 0, 0));
				break;
			default:
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				//stop
				rigidbody->setLinearVelocity(Vector3(0, 0, 0));
				break;
			case SDLK_a:
				//stop
				rigidbody->setLinearVelocity(Vector3(0, 0, 0));
				break;
			case SDLK_s:
				//stop
				rigidbody->setLinearVelocity(Vector3(0, 0, 0));
				break;
			case SDLK_d:
				//stop
				rigidbody->setLinearVelocity(Vector3(0, 0, 0));
				break;
			default:
				break;
			}
		}
	}

private:
};
//for the second player/sprite
class KeyBoard2 : public component
{
public:
	transformComponent* transform;
	RigidBody* rigidbody;


	void init() override
	{
		transform = &entity->getComponent<transformComponent>();
		rigidbody = transform->rigidBody;
	}

	void update() override
	{
		transform = &entity->getComponent<transformComponent>();
		rigidbody = transform->rigidBody;

		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_UP:
				// moving up
				rigidbody->setLinearVelocity(Vector3(0, -100, 0));
				break;
			case SDLK_LEFT:
				//moving left
				rigidbody->setLinearVelocity(Vector3(-100, 0, 0));
				break;
			case SDLK_DOWN:
				//moving down
				rigidbody->setLinearVelocity(Vector3(0, 100, 0));
				break;
			case SDLK_RIGHT:
				//moving right
				rigidbody->setLinearVelocity(Vector3(100, 0, 0));
				break;
			default:
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_UP:
				//stop
				rigidbody->setLinearVelocity(Vector3(0, 0, 0));
				break;
			case SDLK_LEFT:
				//stop
				rigidbody->setLinearVelocity(Vector3(0, 0, 0));
				break;
			case SDLK_DOWN:
				//stop
				rigidbody->setLinearVelocity(Vector3(0, 0, 0));
				break;
			case SDLK_RIGHT:
				//stop
				rigidbody->setLinearVelocity(Vector3(0, 0, 0));
				break;
			default:
				break;
			}
		}
	}

private:
};
