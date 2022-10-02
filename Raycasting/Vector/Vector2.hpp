#ifndef VECTOR2_H
#define VECTOR2_H

class Matrix2;

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Vector2
{
public:
	Vector2(double x, double y);

	Vector2();

	Vector2(const Vector2&) = default;

	Vector2& operator = (const Vector2&) = default;

	~Vector2() = default;

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	double Length();

	void SetValue(double x, double y);

	double GetX() const;
	double GetY() const;

	void SetX(double value);
	void SetY(double value);

	void Rotate(double phi);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	friend Vector2 operator + (const Vector2& left, const Vector2& right);

	friend Vector2 operator - (const Vector2& left, const Vector2& right);

	friend Vector2 operator * (const Vector2& vec, const double number);

	friend Vector2 operator * (const double number, const Vector2& vec);

	friend Vector2 operator / (const Vector2& vec, const double number);

	friend Vector2& operator += (Vector2& left, const Vector2& right);

	friend Vector2& operator -= (Vector2& left, const Vector2& right);

	friend Vector2& operator *= (Vector2& vec, const double number);

	friend Vector2& operator /= (Vector2& vec, const double number);

	friend double operator * (const Vector2& left, const Vector2& right);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	friend Vector2 operator * (const Matrix2& left, const Vector2& right);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

protected:
	double len;

	double x;
	double y;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

inline double Vector2::GetX() const { return x; }
inline double Vector2::GetY() const { return y; }

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !VECTOR2_H