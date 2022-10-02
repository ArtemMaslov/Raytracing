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
	// ����� ����� �������������� ��� ��������� ������������ �������. 
	// 
	// ���������� (��������) ������������ ������� �������� ����������� ������� �������.
	// ������ � ���� ������������ ������� �������� ���� �������, �������� ����� ������ ����������� ����.
	// ��������:
	//     1. ��� x ���������� ������.
	//     2. ��� y ����. 
	//     3. ����� (0, 0) - ����� ������� ����.
	// 
	// ������������ ������� CoordinateSystem - �������� �������������� ������������ ��������. 
	// ��� ������� ����� ��� ��������� ���������� � ������������� ��������� ���������� ��������.
	// ����� ��� ������� ����� ���������� ������ ������������.
	// ��������:
	//     1. ��� x ���������� ������.
	//     2. ��� y ���������� �����.
	//     3. (0, 0) - ���� ����� origin_p �� ������.
	// 
	// ������� _p (pixel) ��������, ��� �������� ���������� � �������� ������.
	// ������� _c (coordinate) ��������, ��� �������� ���������� � �����������.
	// 
	// �������� ��������� ������� CoordinateSystem:
	//     1. ������ ������ width_p � �������� ������������� ������ width_c � �����������.
	//     2. ������ ������ height_p � �������� ������������� ������ height_c � �����������.
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

	// ����������� �������� �� ��������� � �������. xConvert = (width_p) / (width_c);
	// ���������� -> �������   : �������� �� xConvert.
	// �������    -> ����������: �����    �� xConvert.
	const double xConvert;

	// ����������� �������� �� ��������� � �������. yConvert = (height_p) / (height_c);
	// ���������� -> �������   : �������� �� yConvert.
	// �������    -> ����������: �����    �� yConvert.
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