#pragma once

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
	TransformComponent* transform; // Getting the position from the transformed component
	SDL_Texture* texture; // Creating a pointer texture for later use
	SDL_Rect srcRect, destRect; // Create the display rectangles for later use

public:

	SpriteComponent() = default;
	
	SpriteComponent(const char* path) {
		setTex(path);
	}

	~SpriteComponent() { // Remove the texture when we don't need it anymore
		SDL_DestroyTexture(texture);
	}

	void setTex(const char* path) {
		texture = TextureManager::LoadTexture(path); // Changing the texture
	}

	void init() override {

		transform = &entity->getComponent<TransformComponent>(); // Linking this entity to the position component in order to obtain the position and set the position

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
		destRect.w = destRect.h = 64;

	}

	void update() override {

		// Moving the sprite accross the screen 
		destRect.x = (int)transform->position.x; // These needed to be casted as int because the rectangle is expecting integer values
		destRect.y = (int)transform->position.y;

		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void draw() override { // Putting the sprite on screen
		TextureManager::Draw(texture, srcRect, destRect);
	}
};
