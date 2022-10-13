#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y); // Setting the initial position with int x and y
	~GameObject();
	
	void Update(); // update only specifically for this sprite object
	void Render();

private:
	// Position on screen of the sprite
	int xpos = 0;
	int ypos = 0;

	SDL_Texture* objTexture; // Create texture for the sprite
	SDL_Rect srcRect, destRect; // Rectangle to display the sprite
	// Source rectangle is how much of the image would we like to use
	// The destination rectangle is where on the render frame would we like to display the image



};