#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
	
	objTexture = TextureManager::LoadTexture(texturesheet); // Create a texture using the texture manager function

	xpos = x;
	ypos = y;
}

void GameObject::Update() {

	// Setting the default position of the sprites
	xpos++;
	ypos++;

	// Setting the default position and size of the source rectangle
	srcRect.h = 515;
	srcRect.w = 1193;
	srcRect.x = 0;
	srcRect.y = 0;

	// Setting the default poisiton and size of the destination rectangle
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 64;
	destRect.h = 64;


}

void GameObject::Render() {

	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect); // Copy a portion of the texture to the current rendering target
}