#ifndef DRAWING_H
#define DRAWING_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "CoordinateSystem.hpp"
#include "../Vector/Vector.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void DrawLine(sf::RenderWindow& window, 
			  const float x1, const float y1, const float x2, const float y2,
			  const sf::Color& color);

class RenderVector : public Vector
{
public:
	//RenderVector(double x, double y);

	//RenderVector();

	//void DrawCoord(sf::RenderWindow& window, const CoordinateSystem& sc, float x0, float y0);
	//
	//void DrawPixel(sf::RenderWindow& window, float x0, float y0);

	float ArrowWidth  = 16;
	float ArrowHeight = 4;

	sf::Color Color   = sf::Color::Black;

private:
	//void DrawVector(sf::RenderWindow& window, const Point& p1, const Point& p2);
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !DRAWING_H