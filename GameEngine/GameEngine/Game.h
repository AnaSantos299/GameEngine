#pragma once

#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
#include <reactphysics3d/reactphysics3d.h>
//needed for the physics
using namespace reactphysics3d;

class Game
{
public:
	//declaring the physicscommon
	PhysicsCommon physicsCommon;
	//create the world so we can create the body's/colliders
	//in the react physics 3D the world needs to be created before the body's/collider start to be created
	//in this librarys instead of creating the ridgibody directly we need to create the world first so the body can be create in the same
	PhysicsWorld* world = physicsCommon.createPhysicsWorld();

	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clear();

	static SDL_Renderer *renderer;
	static SDL_Event event;

private:
	bool isRunning = false;
	int count = 0;
	SDL_Window* window;


};