#include "Raycasting.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

static bool CheckInSphere(const double radius, const Vector& coord);

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Raycasting::Raycasting(int width, int height, double radius) :
	sceneWidth (width),
	sceneHeight(height),
	sphereRadius(radius),
	coordSys(Point2{width / 2.0, height / 2.0}, width, height, 20, 20),

	colorMaterial(60, 40, 120),
	colorBackground(10, 10, 10),
	lightSource(0, 20, 20),
	colorLightSource(255, 255, 255),
	colorLightAmbient(255, 255, 255),

	ambientCoef(0.1),
	diffusionCoef(0.6)
{
	scene.create(coordSys.GetWidthP(), coordSys.GetHeightP());
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

static bool CheckInSphere(const double radius, const Vector& coord)
{
	return coord * coord <= radius * radius;
}

void Raycasting::Compute()
{
	for (size_t yPixel = 0; yPixel < sceneHeight; yPixel++)
	{
		for (size_t xPixel = 0; xPixel < sceneWidth; xPixel++)
		{
			const Point2 pixel {(double)xPixel, (double)yPixel};
			Vector coord = coordSys.PixelToCoord(pixel);

			if (CheckInSphere(sphereRadius, coord))
			{
				coord.SetZ(sqrt(sphereRadius * sphereRadius - coord * coord));

				Vector lightRay = lightSource - coord;


				sf::Color color = ambientCoef * colorLightAmbient + 

				scene.setPixel(pixel.x, pixel.y, colorMaterial);
			}
			else
			{
				scene.setPixel(pixel.x, pixel.y, colorBackground);
			}
		}
	}
}

void Raycasting::Draw(sf::RenderWindow& window)
{
	Compute();

	sf::Texture texture;
	texture.loadFromImage(scene);

	sf::Sprite sprite(texture);
	window.draw(sprite);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 