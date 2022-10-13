#pragma once

#include "Game.h"


class Map {
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]); // Loading the map
	void DrawMap(); // Drawing the map


private:

	SDL_Rect src, dest; // Create rectangle to hold the source and destination for rendering
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	SDL_Texture* dirt4;
	SDL_Texture* dirt5;
	SDL_Texture* dirt6;
	SDL_Texture* dirt7;

	SDL_Texture* waterTL;
	SDL_Texture* waterTR;
	SDL_Texture* waterBR;
	SDL_Texture* waterBL;

	int map[20][25]; // Creating the size of the map
};
