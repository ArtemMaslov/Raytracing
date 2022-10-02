#include "Graphics.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void DrawLine(sf::RenderWindow& window,
			  const float x1, const float y1, const float x2, const float y2,
			  const sf::Color& color)
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f((float)x1, (float)y1), color),
		sf::Vertex(sf::Vector2f((float)x2, (float)y2), color)
	};
	const size_t lineSize = sizeof(line) / sizeof(sf::Vertex);

	window.draw(line, lineSize, sf::Lines);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

//RenderVector::RenderVector(const double x, const double y) : Vector(x, y) { }

//RenderVector::RenderVector() : RenderVector(0, 0) { }

//void RenderVector::DrawVector(sf::RenderWindow& window, const Point& p1, const Point& p2)
//{
//	// –исуем линию вектора.
//	DrawLine(window, p1.x, p1.y, p2.x, p2.y, Color);
//
//	// –исуем стрелочку.
//	// ¬се расчЄты выполн€ютс€ в пиксел€х.
//	float pixVecWidth  = (float)(p2.x - p1.x);
//	float pixVecHeight = (float)(p2.y - p1.y);
//
//	// ƒлина вектора в пиксел€х.
//	float pixLen = sqrtf(pixVecWidth * pixVecWidth + pixVecHeight * pixVecHeight);
//
//	// ѕереходим в новый базис {e1, e2}. e1 коллинеарен вектору, e2 перпендикул€рен ему.
//	float wa = ArrowWidth  * pixVecWidth;
//	float wb = ArrowWidth  * pixVecHeight;
//	float ha = ArrowHeight * pixVecWidth;
//	float hb = ArrowHeight * pixVecHeight;
//
//	float arrow1X = (- wa - hb) / pixLen;
//	float arrow1Y = (- wb + ha) / pixLen;
//	DrawLine(window, p2.x, p2.y, p2.x + arrow1X, p2.y + arrow1Y, Color);
//
//	float arrow2X = (- wa + hb) / pixLen;
//	float arrow2Y = (- wb - ha) / pixLen;
//	DrawLine(window, p2.x, p2.y, p2.x + arrow2X, p2.y + arrow2Y, Color);
//}
//
//void RenderVector::DrawCoord(sf::RenderWindow& window, const CoordinateSystem& sc, float x0, float y0)
//{
//	Point p1 = sc.CalcPoint(Point{x0, y0});
//	Point p2 = sc.CalcPoint(Point{x0 + x, y0 + y});
//
//	DrawVector(window, p1, p2);
//}
//
//void RenderVector::DrawPixel(sf::RenderWindow& window, float x0, float y0)
//{
//	Point p1 = {x0, y0};
//	Point p2 = {x0 + x, y0 + y};
//
//	DrawVector(window, p1, p2);
//}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 