#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	SDL_Surface* tempSurface = IMG_Load(texture); // Create a surface for the texture
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface); // Create the texture from the created surface above
	SDL_FreeSurface(tempSurface); // Delete the surface

	return  tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest); // Draw any texture that had been passed through to the screen
}
