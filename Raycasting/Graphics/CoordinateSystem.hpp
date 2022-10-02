#ifndef COORDIATE_SYSTEM_H
#define COORDIATE_SYSTEM_H

#include <SFML/Graphics.hpp>

#include "../Vector/Vector3.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

struct Point2
{
	double x;
	double y;
};

class CoordinateSystem
{
	// Далее будут использоваться две различные координатные системы. 
	// 
	// Пиксельная (экранная) координатная система является абстракцией матрицы дисплея.
	// Точкой в этой координатной системе является один пиксель, которому можно задать определённый цвет.
	// Свойства:
	//     1. Ось x направлена вправо.
	//     2. Ось y вниз. 
	//     3. Точка (0, 0) - левый верхний угол.
	// 
	// Координатная система CoordinateSystem - является математической координатной системой. 
	// Эта система нужна для упрощения вычислений и моделирования различных физических объектов.
	// Далее эта система будет называться просто координатной.
	// Свойства:
	//     1. Ось x направлена вправо.
	//     2. Ось y направлена вверх.
	//     3. (0, 0) - есть точка origin_p на экране.
	// 
	// Суффикс _p (pixel) означает, что величина измеряется в пикселях экрана.
	// Суффикс _c (coordinate) означает, что величина измеряется в координатах.
	// 
	// Описание некоторых свойств CoordinateSystem:
	//     1. Ширине экрана width_p в пикселях соответствует ширина width_c в координатах.
	//     2. Высоте экрана height_p в пикселях соответствует высота height_c в координатах.
public:
	CoordinateSystem(Point2 origin, int width_p, int height_p, double width_c, double height_c);

	Point2 CoordToPixel(const Vector3& coordinate) const;

	Vector3 PixelToCoord3(const Point2& pixel) const;

	const Point2& GetOrigin();

	int GetWidthP();
	int GetHeightP();

	void DrawAxes(sf::RenderWindow& window, const sf::Color& color) const;

private:
	const Point2 origin_p;

	const int    width_p;
	const double width_c;

	const int    height_p;
	const double height_c;

	// Коэффициент перевода из координат в пиксели. xConvert = (width_p) / (width_c);
	// Координаты -> пиксели   : умножаем на xConvert.
	// Пиксели    -> координаты: делим    на xConvert.
	const double xConvert;

	// Коэффициент перевода из координат в пиксели. yConvert = (height_p) / (height_c);
	// Координаты -> пиксели   : умножаем на yConvert.
	// Пиксели    -> координаты: делим    на yConvert.
	const double yConvert;

	const double xMin_c;
	const double xMax_c;

	const double yMin_c;
	const double yMax_c;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

inline const Point2& CoordinateSystem::GetOrigin() { return origin_p; }

inline int CoordinateSystem::GetWidthP()  { return width_p;  }
inline int CoordinateSystem::GetHeightP() { return height_p; }

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !COORDIATE_SYSTEM_H