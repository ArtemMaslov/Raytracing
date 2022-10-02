#ifndef MATRIX2_H
#define MATRIX2_H

#include "Vector2.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 


class Matrix2
{;
public:
	static const int rang = 2;
	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
	
	Matrix2(double value[][rang]);

	Matrix2();

	Matrix2(const Matrix2&) = default;

	Matrix2& operator = (const Matrix2&) = default;

	~Matrix2() = default;

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	Matrix2& operator += (const Matrix2& right);

	Matrix2& operator -= (const Matrix2& right);

	Matrix2& operator *= (const double number);

	Matrix2& operator /= (const double number);

	friend Matrix2 operator + (const Matrix2& left, const Matrix2& right);

	friend Matrix2 operator - (const Matrix2& left, const Matrix2& right);

	friend Matrix2 operator * (const Matrix2& left, const double number);

	friend Matrix2 operator * (const double number, const Matrix2& left);

	friend Matrix2 operator / (const Matrix2& left, const double number);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	friend Vector2 operator * (const Matrix2& left, const Vector2& right);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	double value[rang][rang];
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !MATRIX_H