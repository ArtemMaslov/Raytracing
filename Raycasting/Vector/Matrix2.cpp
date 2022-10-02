#include <string>

#include "Matrix2.hpp"

#include "../Graphics/DoubleMath.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Matrix2::Matrix2(double value[rang][rang]) :
	value()
{
	memcpy(this->value, value, rang * rang * sizeof(double));
}

Matrix2::Matrix2() : 
	value()
{

}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Matrix2& Matrix2::operator += (const Matrix2& right)
{
	for (size_t y = 0; y < rang; y++)
	{
		for (size_t x = 0; x < rang; x++)
			value[y][x] += right.value[y][x];
	}
	return *this;
}

Matrix2& Matrix2::operator -= (const Matrix2& right)
{ 
	for (size_t y = 0; y < rang; y++)
	{
		for (size_t x = 0; x < rang; x++)
			value[y][x] -= right.value[y][x];
	}
	return *this;
}


Matrix2& Matrix2::operator *= (const double number)
{
	for (size_t y = 0; y < rang; y++)
	{
		for (size_t x = 0; x < rang; x++)
			value[y][x] *= number;
	}
	return *this;
}

Matrix2& Matrix2::operator /= (const double number)
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

Matrix2 operator + (const Matrix2& left, const Matrix2& right)
{
	Matrix2 res(left);
	return res += right;
}

Matrix2 operator - (const Matrix2& left, const Matrix2& right)
{
	Matrix2 res(left);
	return res -= right;
}

Matrix2 operator * (const Matrix2& left, const double number)
{
	Matrix2 res(left);
	return res *= number;
}

Matrix2 operator * (const double number, const Matrix2& left)
{
	return left * number;
}

Matrix2 operator / (const Matrix2& left, const double number)
{
	Matrix2 res(left);
	return res /= number;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector2 operator * (const Matrix2& left, const Vector2& right)
{
	double x = left.value[0][0] * right.x + left.value[0][1] * right.y;
	double y = left.value[1][0] * right.x + left.value[1][1] * right.y;
	return Vector2(x, y);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 