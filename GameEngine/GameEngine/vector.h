#pragma once
#include <iostream>

class vector
{
public:
	//declaring two variables, x and y
	float x;
	float y;

	vector();
	vector(float x, float y);
	~vector();

	//v1.add(v2), const because it wont be changed
	vector& Add(const vector& vec);
	vector& Subtract(const vector& vec);
	vector& Multiply(const vector& vec);
	vector& Divide(const vector& vec);
	
	
	friend vector& operator+(vector& v1, const vector& v2);
	friend vector& operator-(vector& v1, const vector& v2);
	friend vector& operator*(vector& v1, const vector& v2);
	friend vector& operator/(vector& v1, const vector& v2);

	vector& operator+=(const vector& vec);
	vector& operator-=(const vector& vec);
	vector& operator*=(const vector& vec);
	vector& operator/=(const vector& vec);

	friend std::ostream& operator<<(std::ofstream& stream, const vector& vec);
private:

};