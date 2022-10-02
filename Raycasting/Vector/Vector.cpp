#include <assert.h>
#include <math.h>

#include "Vector.hpp"
#include "../Graphics/Graphics.hpp"

#define CHECK_VECTOR_COORD(vec) \
	assert(vec.x != NAN); \
	assert(vec.y != NAN);

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector::Vector(double x, double y, double z) :
	x(x),
	y(y),
	z(z),
	len(NAN)
{
}

Vector::Vector() : Vector::Vector(0, 0, 0)
{
}

Vector::~Vector()
{
	len = NAN;
	x = NAN;
	y = NAN;
	z = NAN;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

double Vector::Length()
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

void Vector::SetX(double value)
{
	len = NAN;
	x   = value;
}

void Vector::SetY(double value)
{
	len = NAN;
	y   = value;
}

void Vector::SetZ(double value)
{
	len = NAN;
	z   = value;
}

void Vector::SetValue(double x, double y, double z)
{
	len = NAN;
	this->x = x;
	this->y = y;
	this->z = z;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void Vector::Rotate2(double cos_phi, double sin_phi)
{
	double xNew = x * cos_phi - y * sin_phi;
	double yNew = x + sin_phi + y * cos_phi;

	x = xNew;
	y = yNew;
}

Vector operator + (const Vector& left, const Vector& right)
{
	CHECK_VECTOR_COORD(left);
	CHECK_VECTOR_COORD(right);

	Vector sum = left;
	return sum += right;
}

Vector operator - (const Vector& left, const Vector& right)
{
	CHECK_VECTOR_COORD(left);
	CHECK_VECTOR_COORD(right);

	Vector sub = left;
	return sub -= right;
}

Vector operator * (const Vector& vec, const double number)
{
	CHECK_VECTOR_COORD(vec);

	Vector mul = vec;
	return mul *= number;
}

Vector operator * (double number, const Vector& vec)
{
	return vec * number;
}

Vector operator / (const Vector& vec, const double number)
{
	CHECK_VECTOR_COORD(vec);

	if (number == 0)
		throw new std::exception("Деление на 0.");

	Vector div = vec;
	return div /= number;
}

Vector& operator += (Vector& left, const Vector& right)
{
	CHECK_VECTOR_COORD(left);
	CHECK_VECTOR_COORD(right);

	left.x += right.x;
	left.y += right.y;
	left.z += right.z;

	return left;
}

Vector& operator -= (Vector& left, const Vector& right)
{
	CHECK_VECTOR_COORD(left);
	CHECK_VECTOR_COORD(right);

	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;

	return left;
}

Vector& operator *= (Vector& vec, const double number)
{
	CHECK_VECTOR_COORD(vec);

	vec.x *= number;
	vec.y *= number;
	vec.z *= number;

	return vec;
}

Vector& operator /= (Vector& vec, const double number)
{
	CHECK_VECTOR_COORD(vec);

	if (number == 0)
		throw new std::exception("Деление на 0.");

	vec.x /= number;
	vec.y /= number;
	vec.z /= number;

	return vec;
}

double operator * (const Vector& left, const Vector& right)
{
	return left.x * right.x + left.y * right.y + left.z * right.z;
} 

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 