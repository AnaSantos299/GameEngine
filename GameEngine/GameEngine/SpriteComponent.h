#pragma once
#include "components.h"
#include "SDL.h"

class spriteComponent : public component
{
public:
	spriteComponent() = default;
	spriteComponent(const char* pathTexture)
	{
		setTexture(pathTexture);
	}

	void setTexture(const char* pathTexture)
	{
		texture = TextureManager::LoadTexture(pathTexture);
	}


	void init() override
	{
		//transform component, tem um transform dentro e um rigidbody
		transform = &entity->getComponent<transformComponent>();

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		DestRect.w = DestRect.h = 64;
	}

	void update() override
	{
		RigidBody* rb = transform->rigidBody;
		//cast int because the rectangle is expecting an int
		DestRect.x = rb->getTransform().getPosition().x;
		DestRect.y = rb->getTransform().getPosition().y;

	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, DestRect);
	}

private:
	transformComponent *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, DestRect;
};