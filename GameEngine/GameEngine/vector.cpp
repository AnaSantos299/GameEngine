#include "vector.h"
#include <iostream>

vector::vector()
{
	x = 0.0f;
	y = 0.0f;
}

vector::vector(float x, float y)
{
	this->x = x;
	this->y = y;	
}


vector::~vector()
{

}

vector& vector::Add(const vector& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}
vector& vector::Subtract(const vector& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}
vector& vector::Divide(const vector& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;

	return *this;
}
vector& vector::Multiply(const vector& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;

	return *this;
}

vector& operator+(vector& v1, const vector& v2)
{
	return v1.Add(v2);
}

vector& operator-(vector& v1, const vector& v2)
{
	return v1.Subtract(v2);
}

vector& operator*(vector& v1, const vector& v2)
{
	return v1.Multiply(v2);
}

vector& operator/(vector& v1, const vector& v2)
{
	return v1.Divide(v2);
}

vector& vector::operator+=(const vector& vec)
{
	return this->Add(vec);
}

vector& vector::operator-=(const vector& vec)
{
	return this->Subtract(vec);
}

vector& vector::operator*=(const vector& vec)
{
	return this->Multiply(vec);
}

vector& vector::operator/=(const vector& vec)
{
	return this->Divide(vec);
}

std::ostream& operator<<(std::ostream& stream, const vector& vec)
{
	stream << "(" << vec.x << vec.y << ")";
	return stream;
	
}