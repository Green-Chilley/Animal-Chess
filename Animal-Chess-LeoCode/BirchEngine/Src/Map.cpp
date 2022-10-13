#include "Map.h"
#include "TextureManager.h"

// Creating a default map when loading the game

int lvl1[20][25] = { // The integer representation of the field

	{0,0,0,0,0,0,0,0,0,0,0,4,2,5,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,7,2,6,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,10,1,1,1,1,11,0,0,0,0,0,0,0,10,1,1,1,1,11,0,0,0},
	{0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
	{0,0,0,13,1,1,1,1,12,0,0,0,0,0,0,0,13,1,1,1,1,12,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,4,2,5,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,7,2,6,0,0,0,0,0,0,0,0,0,0,0},
};

Map::Map() {
	// Setting the textures for the terrain drawing 
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/water.png");

	dirt4 = TextureManager::LoadTexture("assets/dirt4.png");
	dirt5 = TextureManager::LoadTexture("assets/dirt5.png");
	dirt6 = TextureManager::LoadTexture("assets/dirt6.png");
	dirt7 = TextureManager::LoadTexture("assets/dirt7.png");

	waterTL = TextureManager::LoadTexture("assets/water10.png");
	waterTR = TextureManager::LoadTexture("assets/water11.png");
	waterBR = TextureManager::LoadTexture("assets/water12.png");
	waterBL = TextureManager::LoadTexture("assets/water13.png");

	LoadMap(lvl1);

	src.x = src.y = 0; // Setting the source retangle
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;


}

Map::~Map() { // Destroy the components of the map when its no longer required
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(water);
	SDL_DestroyTexture(dirt);

	SDL_DestroyTexture(dirt4);
	SDL_DestroyTexture(dirt5);
	SDL_DestroyTexture(dirt6);
	SDL_DestroyTexture(dirt7);

	SDL_DestroyTexture(waterTL);
	SDL_DestroyTexture(waterTR);
	SDL_DestroyTexture(waterBR);
	SDL_DestroyTexture(waterBL);
}

void Map::LoadMap(int arr[20][25]) { // Take in the integer array of the playing field

	for (int row = 0; row < 20; row++) { // Loops to equate playing field with the integer array
		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap() {

	int type = 0;

	for (int row = 0; row < 20; row++) { // Loops to equate playing field with the integer array
		for (int column = 0; column < 25; column++) {

			type = map[row][column]; // Check what value in each of the array is

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type) { // Draw the map based upon the values 0,1 or 2 represent dirt grass or water
			case 0:
				TextureManager::Draw(grass, src, dest);
				break;
			case 1:
				TextureManager::Draw(water, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;

			case 4:
				TextureManager::Draw(dirt4, src, dest);
				break;
			case 5:
				TextureManager::Draw(dirt5, src, dest);
				break;
			case 6:
				TextureManager::Draw(dirt6, src, dest);
				break;
			case 7:
				TextureManager::Draw(dirt7, src, dest);
				break;

			case 10:
				TextureManager::Draw(waterTL, src, dest);
				break;
			case 11:
				TextureManager::Draw(waterTR, src, dest);
				break;
			case 12:
				TextureManager::Draw(waterBR, src, dest);
				break;
			case 13:
				TextureManager::Draw(waterBL, src, dest);
				break;
			default:
				break;
			}
		}
	}

}