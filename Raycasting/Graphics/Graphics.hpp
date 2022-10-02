#ifndef DRAWING_H
#define DRAWING_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "CoordinateSystem.hpp"
#include "../Vector/Vector2.hpp"
#include "../Vector/Vector3.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void DrawLine(sf::RenderWindow& window, const Point2& point1, const Point2& point2, const sf::Color& color);

class RenderVector
{
public:
	RenderVector(sf::RenderWindow& window, const CoordinateSystem& coordSys);

	void Draw(const Vector3& startPoint, const Vector3& vector, const sf::Color& color = sf::Color::Black);

private:
	const float ArrowWidth  = 16;
	const float ArrowHeight = 4;

	sf::RenderWindow& window;
	const CoordinateSystem& coordSys;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !DRAWING_H