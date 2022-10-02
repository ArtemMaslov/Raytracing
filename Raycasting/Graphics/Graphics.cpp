#include "Graphics.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void DrawLine(sf::RenderWindow& window, const Point2& point1, const Point2& point2, const sf::Color& color)
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f((float)point1.x, (float)point1.y), color),
		sf::Vertex(sf::Vector2f((float)point2.x, (float)point2.y), color)
	};
	const size_t lineSize = sizeof(line) / sizeof(sf::Vertex);

	window.draw(line, lineSize, sf::Lines);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

RenderVector::RenderVector(sf::RenderWindow& window, const CoordinateSystem& coordSys) :
	window(window),
	coordSys(coordSys)
{
}

void RenderVector::Draw(const Vector3& startPoint, const Vector3& vector, const sf::Color& color)
{
	Point2 p1 = coordSys.CoordToPixel(startPoint);
	Point2 p2 = coordSys.CoordToPixel(startPoint + vector);
	
	// –исуем линию вектора.
	DrawLine(window, p1, p2, color);
		
	// –исуем стрелочку.
	// ¬се расчЄты выполн€ютс€ в пиксел€х.
	float pixVecWidth  = (float)(p2.x - p1.x);
	float pixVecHeight = (float)(p2.y - p1.y);
	
	// ƒлина вектора в пиксел€х.
	float pixLen = sqrtf(pixVecWidth * pixVecWidth + pixVecHeight * pixVecHeight);
	
	// ѕереходим в новый базис {e1, e2}. e1 коллинеарен вектору, e2 перпендикул€рен ему.
	float wa = ArrowWidth  * pixVecWidth;
	float wb = ArrowWidth  * pixVecHeight;
	float ha = ArrowHeight * pixVecWidth;
	float hb = ArrowHeight * pixVecHeight;
	
	float arrow1X = (- wa - hb) / pixLen;
	float arrow1Y = (- wb + ha) / pixLen;
	DrawLine(window, p2, Point2 {p2.x + arrow1X, p2.y + arrow1Y}, color);
	
	float arrow2X = (- wa + hb) / pixLen;
	float arrow2Y = (- wb - ha) / pixLen;
	DrawLine(window, p2, Point2 {p2.x + arrow2X, p2.y + arrow2Y}, color);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 