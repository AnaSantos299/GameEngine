#pragma once
#include "Game.h"

class GameObject
{
public:

	void* entityGameObject;

	GameObject(const char* texturesheet, int x, int y, void* entityGameObject2);
	
	void Update();
	void Render();


private:
	int xpos;
	int ypos;

	SDL_Texture *objTexture;
	SDL_Rect srcRect, destRect;



};

