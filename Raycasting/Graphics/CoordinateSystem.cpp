#include "CoordinateSystem.hpp"
#include "Graphics.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

CoordinateSystem::CoordinateSystem(Point2 origin, int width_p, int height_p, double width_c, double height_c) :
	origin_p(origin),

	width_p (width_p),
	width_c (width_c),

	height_p(height_p),
	height_c(height_c),

	xConvert(width_p  / width_c),
	yConvert(height_p / height_c),

	xMin_c  ( -origin.x / xConvert),
	xMax_c  ((width_p - origin.x) / xConvert),

	yMin_c  ((origin.y - height_p) / yConvert),
	yMax_c  (origin.y / yConvert)
{
}

Point2 CoordinateSystem::CoordToPixel(const Vector3& coordinate) const
{
	double newX = origin_p.x + coordinate.GetX() * xConvert;
	double newY = origin_p.y - coordinate.GetY() * yConvert;

	return Point2{newX, newY};
}

Vector3 CoordinateSystem::PixelToCoord3(const Point2& pixel) const
{
	double newX = (pixel.x - origin_p.x) / xConvert;
	double newY = -(pixel.y - origin_p.y) / yConvert;

	return Vector3(newX, newY, 0);
}

void CoordinateSystem::DrawAxes(sf::RenderWindow& window, const sf::Color& color) const
{
	RenderVector rendVec(window, *this);

	Vector3 axisX(width_c, 0, 0);
	Vector3 axisY(0, height_c, 0);

	rendVec.Draw(Vector3(xMin_c, 0, 0), axisX, color);
	rendVec.Draw(Vector3(0, yMin_c, 0), axisY, color);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 