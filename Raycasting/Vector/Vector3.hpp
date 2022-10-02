#ifndef VECTOR3_H
#define VECTOR3_H

class Matrix3;

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Vector3
{
public:
	Vector3(double x, double y, double z);

	Vector3();

	Vector3(const Vector3&) = default;

	Vector3& operator = (const Vector3&) = default;

	~Vector3() = default;

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	double Length();

	void SetValue(double x, double y, double z);

	double GetX() const;
	double GetY() const;
	double GetZ() const;

	void SetX(double value);
	void SetY(double value);
	void SetZ(double value);

	static void Mirror(Vector3& vector, Vector3& axis, Vector3& out_res);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	friend Vector3 operator + (const Vector3& left, const Vector3& right);

	friend Vector3 operator - (const Vector3& left, const Vector3& right);

	friend Vector3 operator * (const Vector3& vec, const double number);

	friend Vector3 operator * (const double number, const Vector3& vec);

	friend Vector3 operator / (const Vector3& vec, const double number);

	friend Vector3& operator += (Vector3& left, const Vector3& right);

	friend Vector3& operator -= (Vector3& left, const Vector3& right);

	friend Vector3& operator *= (Vector3& vec, const double number);

	friend Vector3& operator /= (Vector3& vec, const double number);

	friend double operator * (const Vector3& left, const Vector3& right);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

	friend Vector3 operator * (const Matrix3& left, const Vector3& right);

	//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

protected:
	double len;

	double x;
	double y;
	double z;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

inline double Vector3::GetX() const { return x; }
inline double Vector3::GetY() const { return y; }
inline double Vector3::GetZ() const { return z; }

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !VECTOR3_H