#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:

	Vector2D position; // Create an object in Vector2D
	Vector2D velocity;
	
	int height = 64;
	int width = 64;
	int scale = 1;

	int speed = 3;

	bool canMove = false;



	TransformComponent() {
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent(float x, float y) {

		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int scale){

		position.x = x;
		position.y = y;
		height = h;
		width = w;
		this->scale = scale;
	}

	TransformComponent(int scale) {
		position.x = 0.0f;
		position.y = 0.0f;
		this->scale = scale;
	}

	// Returning the positions
	//int x() { return xpos; }
	//void x(int x) { xpos = x; }

	//int y() { return ypos; }
	//void y(int y) { ypos = y; }

	//void setPos(int x, int y) { xpos = x; ypos = y; }

	void init() override {
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override { // Override the update function of ECS
		position.x += velocity.x * speed; // Change 3 pixel at a time
		position.y += velocity.y * speed; 
	}

	void updateCanMove(bool status) {
		canMove = status;
		std::cout << "true" << std::endl;
	}

	

};