#include <string>

#include "Matrix3.hpp"

#include "../Graphics/DoubleMath.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Matrix3::Matrix3(double value[rang][rang]) :
	value()
{
	memcpy(this->value, value, rang * rang * sizeof(double));
}

Matrix3::Matrix3() : 
	value()
{

}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Matrix3& Matrix3::operator += (const Matrix3& right)
{
	for (size_t y = 0; y < rang; y++)
	{
		for (size_t x = 0; x < rang; x++)
			value[y][x] += right.value[y][x];
	}
	return *this;
}

Matrix3& Matrix3::operator -= (const Matrix3& right)
{ 
	for (size_t y = 0; y < rang; y++)
	{
		for (size_t x = 0; x < rang; x++)
			value[y][x] -= right.value[y][x];
	}
	return *this;
}


Matrix3& Matrix3::operator *= (const double number)
{
	for (size_t y = 0; y < rang; y++)
	{
		for (size_t x = 0; x < rang; x++)
			value[y][x] *= number;
	}
	return *this;
}

Matrix3& Matrix3::operator /= (const double number)
{
	if (DoubleEqual(number, 0.0))
		throw new std::exception("Деление на 0.");

	for (size_t y = 0; y < rang; y++)
	{
		for (size_t x = 0; x < rang; x++)
			value[y][x] /= number;
	}
	return *this;
}

Matrix3 operator + (const Matrix3& left, const Matrix3& right)
{
	Matrix3 res(left);
	return res += right;
}

Matrix3 operator - (const Matrix3& left, const Matrix3& right)
{
	Matrix3 res(left);
	return res -= right;
}

Matrix3 operator * (const Matrix3& left, const double number)
{
	Matrix3 res(left);
	return res *= number;
}

Matrix3 operator * (const double number, const Matrix3& left)
{
	return left * number;
}

Matrix3 operator / (const Matrix3& left, const double number)
{
	Matrix3 res(left);
	return res /= number;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector3 operator * (const Matrix3& left, const Vector3& right)
{
	double x = left.value[0][0] * right.x + left.value[0][1] * right.y + left.value[0][2] * right.z;
	double y = left.value[1][0] * right.x + left.value[1][1] * right.y + left.value[1][2] * right.z;
	double z = left.value[2][0] * right.x + left.value[2][1] * right.y + left.value[2][2] * right.z;
	return Vector3(x, y, z);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 