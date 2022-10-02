#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SFML/Graphics.hpp>

#include "../Vector/Vector.hpp"
#include "../Graphics/CoordinateSystem.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Raycasting
{
public:
	Raycasting(int width, int height, double radius = 10);

	void Draw(sf::RenderWindow& window);

private:
	void Compute();

	const double sphereRadius;

	const int sceneWidth;
	const int sceneHeight;

	double ambientCoef;
	double diffusionCoef;

	sf::Color colorMaterial;
	sf::Color colorBackground;

	sf::Color colorLightSource;
	sf::Color colorLightAmbient;

	sf::Image scene;
	CoordinateSystem coordSys;

	Vector lightSource;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !RAYCASTING_H