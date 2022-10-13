#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60; // 60 frames per second, closest to the refresh rate of the monitors
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart; // To know how long the game is running for
	int frametime;
	
	game = new Game();
	game->init("GameWindow", 800, 640, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks(); // Get how many seconds it has been since we first initialise SDL

		game->handleEvents();
		game->update();
		game->render();

		frametime = SDL_GetTicks() - frameStart; // Get time how long it took

		if (frameDelay > frametime) { // If the delay time is more than the time it actually took for everything to run
			SDL_Delay(frameDelay - frametime); // Reduce the delay time to the correct amounts
		}
	}

	game->clean();
	return 0;
}