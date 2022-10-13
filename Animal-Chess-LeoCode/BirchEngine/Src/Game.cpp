#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"


Map* map;
 
SDL_Renderer* Game::renderer = nullptr; // Setting the renderer pointer to null

SDL_Event Game::event; // Create an event

Manager manager;
auto& blueMouse(manager.addEntity());
auto& blueCat(manager.addEntity());
auto& newAnimal2(manager.addEntity());
auto& highlight(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0; /* 0 means not full screen*/
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN; /* Full screen or not depend on the status of flag*/
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // Initialise everything needed for a window
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags); // Create a window at the center
		renderer = SDL_CreateRenderer(window, -1, 0); // Create a renderer passing the window
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);// If the renderer is created sucesfully, set the draw color to white
		}

		isRunning = true; // If everything runs successful, the program is running
	}

	
	map = new Map(); // Create a new map object

	//ECS inplementation

	blueMouse.addcomponent<TransformComponent>(2); // Add position to the new animal entity
	// When using the methods from the component class which is created using the template method
	// Calling it in the form of entity.methodName<componentType>().specificMethodOfComponentType()...
	
	blueMouse.addcomponent<SpriteComponent>("assets/bluemouse.png"); // Add sprite component to animal entity
	blueMouse.addcomponent<ColliderComponent>("mouse");

	blueCat.addcomponent<TransformComponent>(300.0f, 300.0f, 400, 20, 1);
	blueCat.addcomponent<SpriteComponent>("assets/bluecat.png");
	blueCat.addcomponent<ColliderComponent>("cat");

	newAnimal2.addcomponent<TransformComponent>(300.0f, 300.0f, 400, 20, 1);
	newAnimal2.addcomponent<SpriteComponent>("assets/dirt.png");
	newAnimal2.addcomponent<ColliderComponent>("cat");

	highlight.addcomponent<TransformComponent>(1);
	highlight.addcomponent<SpriteComponent>("assets/highlight.png");
	highlight.addcomponent<KeyboardController>();
	highlight.addcomponent<ColliderComponent>("hightlight");

}

void Game::handleEvents()
{
	

	SDL_PollEvent(&event); // Way to receive an event from the system and put it into a queue

	switch (event.type) // Check the type of the event
	{
	case SDL_QUIT : // If the User press the cross to close the window, the event will be a quit
		isRunning = false; // Then the game will stop running
		break;
	default:
		break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();
	std::cout << blueMouse.getComponent<TransformComponent>().position.x << "," << blueMouse.getComponent<TransformComponent>().position.y<<std::endl;
	
	if (blueMouse.getComponent<TransformComponent>().position.y > 10) {
		blueMouse.getComponent<TransformComponent>().updateCanMove(true);
	}

	// checking for collision
	if (Collision::AABB(blueMouse.getComponent<ColliderComponent>().collider, newAnimal2.getComponent<ColliderComponent>().collider)) {
		std::cout << "Wall.Hit" << std::endl;
	}

	if (Collision::AABB(blueMouse.getComponent<ColliderComponent>().collider, blueCat.getComponent<ColliderComponent>().collider)) {
		std::cout << "Blue cat hit" << std::endl;
	}
	
}

void Game::render()
{
	SDL_RenderClear(renderer); // Delete any rendering from the past up to this point
	map->DrawMap(); // Draw map first then the pieces on top

	manager.draw();

	SDL_RenderPresent(renderer); // Display the current rendered items
}

void Game::clean()
{
	SDL_DestroyWindow(window); // Delete the window
	SDL_DestroyRenderer(renderer); // Delete the renderer
	SDL_Quit(); // Quit the game
}