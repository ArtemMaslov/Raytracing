#include <assert.h>

#include "Vector3.hpp"

#include "../Graphics/DoubleMath.hpp"
#include "../Graphics/Graphics.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector3::Vector3(double x, double y, double z) :
	x(x),
	y(y),
	z(z),
	len(NAN)
{
}

Vector3::Vector3() : Vector3::Vector3(0, 0, 0)
{
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

double Vector3::Length()
{
	if (!_isnan(len))
	{
		return len;
	}
	else
	{
		len = std::sqrt(x * x + y * y + z * z);

		return len;
	}
}

void Vector3::SetX(double value)
{
	len = NAN;
	x   = value;
}

void Vector3::SetY(double value)
{
	len = NAN;
	y   = value;
}

void Vector3::SetZ(double value)
{
	len = NAN;
	z   = value;
}

void Vector3::SetValue(double x, double y, double z)
{
	len = NAN;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::Mirror(Vector3& vector, Vector3& axis, Vector3& out_res)
{
	double axisLen = axis.Length();

	out_res = 2 * (vector * axis) / (axisLen * axisLen) * axis;
	out_res -= vector;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector3 operator + (const Vector3& left, const Vector3& right)
{
	Vector3 sum = left;
	return sum += right;
}

Vector3 operator - (const Vector3& left, const Vector3& right)
{
	Vector3 sub = left;
	return sub -= right;
}

Vector3 operator * (const Vector3& vec, const double number)
{
	Vector3 mul = vec;
	return mul *= number;
}

Vector3 operator * (double number, const Vector3& vec)
{
	return vec * number;
}

Vector3 operator / (const Vector3& vec, const double number)
{
	Vector3 div = vec;
	return div /= number;
}

Vector3& operator += (Vector3& left, const Vector3& right)
{
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;

	return left;
}

Vector3& operator -= (Vector3& left, const Vector3& right)
{
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;

	return left;
}

Vector3& operator *= (Vector3& vec, const double number)
{
	vec.x *= number;
	vec.y *= number;
	vec.z *= number;

	return vec;
}

Vector3& operator /= (Vector3& vec, const double number)
{
	if (DoubleEqual(number, 0.0))
		throw new std::exception("Деление на 0.");

	vec.x /= number;
	vec.y /= number;
	vec.z /= number;

	return vec;
}

double operator * (const Vector3& left, const Vector3& right)
{
	return left.x * right.x + left.y * right.y + left.z * right.z;
} 

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 