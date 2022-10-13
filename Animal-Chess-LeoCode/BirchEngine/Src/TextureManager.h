#pragma once

#include "Game.h"

class TextureManager {
public:
	// Automatically create a texture for any item on screen
	static SDL_Texture* LoadTexture(const char* fileName); // Want to call it as a class function
																			// Therefore there will be no object created for this class
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest); // Draw the terrain for the playing field
};

