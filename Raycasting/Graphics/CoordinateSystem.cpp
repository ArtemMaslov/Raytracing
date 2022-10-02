#include "CoordinateSystem.hpp"
#include "Graphics.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

CoordinateSystem::CoordinateSystem(Point2 origin, int width_p, int height_p, double width_c, double height_c) :
	origin_p(origin),
	width_p (width_p),
	height_p(height_p),
	width_c (width_c),
	height_c(height_c)
	// xConvert(xConvert),
	// yConvert(yConvert)
{
	xConvert = (width_p)  / (width_c);
	yConvert = (height_p) / (height_c);
}

Point2 CoordinateSystem::CoordToPixel(const Vector& coordinate) const
{
	double newX = origin_p.x + coordinate.GetX() * xConvert;
	double newY = origin_p.y + coordinate.GetY() * yConvert;

	return Point2{newX, newY};
}

Vector CoordinateSystem::PixelToCoord(const Point2& pixel) const
{
	double newX = (pixel.x - origin_p.x) / xConvert;
	double newY = (pixel.y - origin_p.y) / yConvert;

	return Vector(newX, newY, 0);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 