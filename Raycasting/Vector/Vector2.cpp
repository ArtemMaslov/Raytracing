#include <assert.h>

#include "Vector2.hpp"

#include "../Graphics/DoubleMath.hpp"
#include "../Graphics/Graphics.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector2::Vector2(double x, double y) :
	x(x),
	y(y),
	len(NAN)
{
}

Vector2::Vector2() : Vector2::Vector2(0, 0)
{
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

double Vector2::Length()
{
	if (!_isnan(len))
	{
		return len;
	}
	else
	{
		len = sqrt(x * x + y * y);

		return len;
	}
}

void Vector2::SetX(double value)
{
	len = NAN;
	x   = value;
}

void Vector2::SetY(double value)
{
	len = NAN;
	y   = value;
}

void Vector2::SetValue(double x, double y)
{
	len = NAN;
	this->x = x;
	this->y = y;
}

void Vector2::Rotate(double phi)
{
	double cos_phi = std::cos(phi);
	double sin_phi = std::sin(phi);

	double newX = x * cos_phi - y * sin_phi;
	double newY = x * sin_phi + y * cos_phi;

	x = newX;
	y = newY;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector2 operator + (const Vector2& left, const Vector2& right)
{
	Vector2 sum = left;
	return sum += right;
}

Vector2 operator - (const Vector2& left, const Vector2& right)
{
	Vector2 sub = left;
	return sub -= right;
}

Vector2 operator * (const Vector2& vec, const double number)
{
	Vector2 mul = vec;
	return mul *= number;
}

Vector2 operator * (double number, const Vector2& vec)
{
	return vec * number;
}

Vector2 operator / (const Vector2& vec, const double number)
{
	Vector2 div = vec;
	return div /= number;
}

Vector2& operator += (Vector2& left, const Vector2& right)
{
	left.x += right.x;
	left.y += right.y;

	return left;
}

Vector2& operator -= (Vector2& left, const Vector2& right)
{
	left.x -= right.x;
	left.y -= right.y;

	return left;
}

Vector2& operator *= (Vector2& vec, const double number)
{
	vec.x *= number;
	vec.y *= number;

	return vec;
}

Vector2& operator /= (Vector2& vec, const double number)
{
	if (DoubleEqual(number, 0.0))
		throw new std::exception("Деление на 0.");

	vec.x /= number;
	vec.y /= number;

	return vec;
}

double operator * (const Vector2& left, const Vector2& right)
{
	return left.x * right.x + left.y * right.y;
} 

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 