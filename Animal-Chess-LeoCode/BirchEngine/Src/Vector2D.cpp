#include "Vector2D.h"

Vector2D::Vector2D() {
	x = 0.0f;
	y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}


// Method defintion for vector operation
Vector2D& Vector2D::Add(const Vector2D& vec) {
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vec) {
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vec) {
	this->x *= vec.x;
	this->y *= vec.y;

	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vec) {
	this->x /= vec.x;
	this->y /= vec.y;

	return *this;
}


// Method definition for operators + - * /
 Vector2D& operator+(Vector2D& v1, const Vector2D& v2) {
	 return v1.Add(v2);
}

 Vector2D& operator-(Vector2D& v1, const Vector2D& v2) {
	 return v1.Subtract(v2);
 }

 Vector2D& operator*(Vector2D& v1, const Vector2D& v2) {
	 return v1.Multiply(v2);
 }

 Vector2D& operator/(Vector2D& v1, const Vector2D& v2) {
	 return v1.Divide(v2);
 }


 // Method definition for operators += -= *= /=
 Vector2D& Vector2D::operator+=(const Vector2D& vec) {
	 return this->Add(vec);
 }

 Vector2D& Vector2D::operator-=(const Vector2D& vec) {
	 return this->Subtract(vec);
 }

 Vector2D& Vector2D::operator*=(const Vector2D& vec) {
	 return this->Multiply(vec);
 }

 Vector2D& Vector2D::operator/=(const Vector2D& vec) {
	 return this->Divide(vec);
 }

 // Method definition of returning the position of the vectors
 std::ostream& operator<<(std::ostream& stream, const Vector2D& vec) {
	 stream << "(" << vec.x << "," << vec.y << ")"; // Output the position similar to std::cout
	 return stream;
 }