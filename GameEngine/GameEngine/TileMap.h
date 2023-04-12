#pragma once
#include "Game.h"

class TileMap
{
public:
	TileMap();
	~TileMap();

	void LoadMap(int array[20][25]);
	void DrawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture *limitPoint;
	SDL_Texture *Point;
	SDL_Texture *offPoint;
	
	int map[20][25];

};