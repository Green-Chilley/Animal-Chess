#pragma once
#include "SDL.h"

class Collision {
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB); //Access Align Bounding Box, check the x and y position of each rectangle to see if they overlap
};