#ifndef VECTOR_H
#define VECTOR_H

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Vector
{
public:
	Vector(double x, double y, double z);

	Vector();

	~Vector();

	double Length();

	void SetValue(double x, double y, double z);

	double GetX() const;
	double GetY() const;
	double GetZ() const;

	void SetX(double value);
	void SetY(double value);
	void SetZ(double value);

	void Rotate2(double cos_phi, double sin_phi);

	friend Vector operator + (const Vector& left, const Vector& right);

	friend Vector operator - (const Vector& left, const Vector& right);

	friend Vector operator * (const Vector& vec, const double number);

	friend Vector operator * (const double number, const Vector& vec);

	friend Vector operator / (const Vector& vec, const double number);

	friend Vector& operator += (Vector& left, const Vector& right);

	friend Vector& operator -= (Vector& left, const Vector& right);

	friend Vector& operator *= (Vector& vec, const double number);

	friend Vector& operator /= (Vector& vec, const double number);

	friend double operator * (const Vector& left, const Vector& right);

protected:
	double len;

	double x;
	double y;
	double z;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

inline double Vector::GetX() const { return x; }
inline double Vector::GetY() const { return y; }
inline double Vector::GetZ() const { return z; }

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !VECTOR_H