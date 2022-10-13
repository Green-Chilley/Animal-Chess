#pragma once

#include "SDL.h"
#include <iostream>
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer* renderer; // Create a static renderer that every object could use instead of creating it in every class
	static SDL_Event  event;
private:
	bool isRunning = false;
	int cnt = 0;
	SDL_Window *window;
};