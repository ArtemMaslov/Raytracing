#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SFML/Graphics.hpp>

#include "../Vector/Vector3.hpp"
#include "../Graphics/Color.hpp"
#include "../Graphics/CoordinateSystem.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Raycasting
{
public:
	Raycasting(int width, int height, double radius = 10);

	void Draw(sf::RenderWindow& window);

	double ambientCoef;
	double diffusionCoef;
	double glareCoef;
	double glareCosExp;

	Color colorMaterial;
	Color colorBackground;

	Color colorLightSource;
	Color colorLightAmbient;

	Vector3 lightSource;
	Vector3 viewPoint;

private:
	void Compute();

	const double sphereRadius;

	const int sceneWidth;
	const int sceneHeight;

	sf::Image scene;
	CoordinateSystem coordSys;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !RAYCASTING_H