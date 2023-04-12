#include "Game.h"
#include "fmod.h"
#include <fmod_studio.hpp>

Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	//unsigned int 32 bits, massive integer
	Uint32 framestart;
	int frameTime;


	game = new Game();
	game->init("GameWindow", 800, 600, false);

	while (game->running())
	{
		framestart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - framestart;

		if (frameDelay > frameTime)
		{
			//delay by the difference
			SDL_Delay(frameDelay - frameTime);
		}


	}
	game->clear();
	return 0;
}

