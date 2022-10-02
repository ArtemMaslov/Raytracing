#ifndef MATRIX3_H
#define MATRIX3_H

#include "Vector3.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Matrix3
{;
public:
	static const int rang = 3;

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	Matrix3(double value[][rang]);

	Matrix3();

	Matrix3(const Matrix3&) = default;

	Matrix3& operator = (const Matrix3&) = default;

	~Matrix3() = default;

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	Matrix3& operator += (const Matrix3& right);

	Matrix3& operator -= (const Matrix3& right);

	Matrix3& operator *= (const double number);

	Matrix3& operator /= (const double number);

	friend Matrix3 operator + (const Matrix3& left, const Matrix3& right);

	friend Matrix3 operator - (const Matrix3& left, const Matrix3& right);

	friend Matrix3 operator * (const Matrix3& left, const double number);

	friend Matrix3 operator * (const double number, const Matrix3& left);

	friend Matrix3 operator / (const Matrix3& left, const double number);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	friend Vector3 operator * (const Matrix3& left, const Vector3& right);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	double value[rang][rang];
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !MATRIX3_H