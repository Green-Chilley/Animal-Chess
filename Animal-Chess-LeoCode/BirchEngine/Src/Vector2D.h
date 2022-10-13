#pragma once

#include <iostream>

class Vector2D { // Vector for the sprite to move around
public:
	// Coordinate of the vector
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);

	// Method for adding and subtracting vectors

	Vector2D& Add(const Vector2D& vec); // Returning a reference to a vector
	Vector2D& Subtract(const Vector2D& vec); // Returning a reference to a vector
	Vector2D& Multiply(const Vector2D& vec); // Returning a reference to a vector
	Vector2D& Divide(const Vector2D& vec); // Returning a reference to a vector

	// Add method to use the symbols + - * / instead of .Add or .Subtract....

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2); // friend is a function that can access private, protected and public members of a class
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	// Override +=, -= ....
	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);

	//Display operator
	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec); // a reference to output the position of a vector
	
};
