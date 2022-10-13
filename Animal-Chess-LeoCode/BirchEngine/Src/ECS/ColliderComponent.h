#pragma once
#include <string>
#include "SDL.h"
#include "ECS.h"
#include "TransformComponent.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	std::string tag; // When detect the collision, pull up the tag from the object hit to identify the object hit

	TransformComponent* transform;

	ColliderComponent(std::string t) { // Setting the name of the tag
		tag = t;
	} 

	void init() override {
		if (!entity->hasComponent<TransformComponent>()) { // If the entity doesn't have a component
			entity->addcomponent<TransformComponent>(); // Add the transform component to the entity
		}
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		collider.x = static_cast<int> (transform->position.x); // Static cast to convert from float to integer
		collider.y = static_cast<int> (transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale; 
	}


};