#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>

#include <SFML/Graphics.hpp>

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Color
{
public:
	float R;
	float G;
	float B;

	Color& operator += (const Color& color);

	Color& operator -= (const Color& color);

	Color& operator *= (const double number);

	Color& operator /= (const double number);

	friend Color operator + (const Color& left, const Color& right);

	friend Color operator - (const Color& left, const Color& rigth);

	friend Color operator * (const Color& color, const double number);

	friend Color operator * (const double number, const Color& color);

	friend Color operator * (const Color& left, const Color& right);

	friend Color operator / (const Color& color, const double number);

	sf::Color Convert();
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !COLOR_H