 #include "Game.h"
#include "TextureManager.h"
#include "TileMap.h"
#include "components.h"
#include "vector.h"
#include "GameObject.h"
#include "fmod.h"
#include <fmod_studio.hpp>

//for textures
SDL_Event Game::event;

TileMap *map;
SDL_Renderer* Game::renderer = nullptr;

Manager manager;
//will create the player
auto& player(manager.addEntity());
auto& player2(manager.addEntity());


//----------------------------------GAME CONSTRUCTOR--------------------
Game::Game()
{}
//----------------------------------GAME DESTRUCTOR----------------------
Game::~Game()
{}

//-----------------------------------INIT :3------------------------------
void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}


	map = new TileMap();
	//position where the player starts
	player.addComponent<transformComponent>(&physicsCommon, world, 50, 0);
	player.addComponent<spriteComponent>("Assests/ss.png");
	player.addComponent<KeyBoard>();

	//player 2
	//primeiro mexe em movimento linha, o segundo coluna, ou seja >/^ 
	player2.addComponent<transformComponent>(&physicsCommon, world, 50, 200);
	player2.addComponent<spriteComponent>("Assests/ss.png");
	player2.addComponent <KeyBoard2>();

	//MUSIC WARNING THE MUSIC IS VERY LOUD
	FMOD::Studio::System* system = NULL;
	FMOD::Studio::System::create(&system);

	FMOD::System* lowLevelSystem = NULL;

	system->getLowLevelSystem(&lowLevelSystem);

	lowLevelSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_STEREO, 0);
	system->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, NULL);

	FMOD::Sound* music = NULL;
	//FMOD_LOOP_NORMAL the music will play in loop till the window is closed
	lowLevelSystem->createSound("music.mp3", FMOD_LOOP_NORMAL, NULL, &music);
	
	FMOD::Channel* musicChannel = NULL;

		lowLevelSystem->playSound(music, NULL, false, &musicChannel);
	
	
	system->update();
	//--------------------------------------------------------------
}

//-----------------------------------HANDLE EVENTS U.U---------------------------------
void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
//-------------------------------------UPDATE----------------------------------
void Game::update()
{
	world->update(1.f/60.f);
	manager.refresh();
	manager.update();

}
//---------------------------------------RENDER--------------------------------
void Game::render()
{
	SDL_RenderClear(renderer);
	//paint first go on the back, paint last come on the front
	//render for textures
	map->DrawMap();
	manager.Draw();	
	//will update the window with any rendering performed since the previous
	SDL_RenderPresent(renderer);

}
//---------------------------------------CLEAR!!-----------------------------------
void Game::clear()
{
	//destroying the window
	SDL_DestroyWindow(window);
	//destroying the renderer
	SDL_DestroyRenderer(renderer);
	//Shut Down SDL
	SDL_Quit();
	//destroying the physics world needed for the body's
	physicsCommon.destroyPhysicsWorld(world);
}

