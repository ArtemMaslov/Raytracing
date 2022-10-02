#include "Color.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Color& Color::operator += (const Color& color)
{
	R += color.R;
	G += color.G;
	B += color.B;

	return *this;
}

Color& Color::operator -= (const Color& color)
{
	R -= color.R;
	G -= color.G;
	B -= color.B;

	return *this;
}

Color& Color::operator *= (const double number)
{
	R *= number;
	G *= number;
	B *= number;

	return *this;
}

Color& Color::operator /= (const double number)
{
	R /= number;
	G /= number;
	B /= number;

	return *this;
}

Color operator + (const Color& left, const Color& right)
{
	Color res = left;
	return res += right;
}

Color operator - (const Color& left, const Color& rigth)
{
	Color res = left;
	return res -= rigth;
}

Color operator * (const Color& color, const double number)
{
	Color res = color;
	return res *= number;
}

Color operator * (const double number, const Color& color)
{
	return color * number;
}

Color operator * (const Color& left, const Color& right)
{
	Color color{left.R * right.R, 
				left.G * right.G,
				left.B * right.B};
	return color;
}

Color operator / (const Color& color, const double number)
{
	Color res = color;
	return res /= number;
}

static double ClampColor(double num)
{
	if (num < 0)
		num = -num;
	if (num > 1.0)
		num = 1.0;

	return num;
}

sf::Color Color::Convert()
{
	sf::Uint8 maxPixel = 255;
	sf::Uint8 newR = maxPixel * ClampColor(R);
	sf::Uint8 newG = maxPixel * ClampColor(G);
	sf::Uint8 newB = maxPixel * ClampColor(B);

	return sf::Color(newR, newG, newB);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 