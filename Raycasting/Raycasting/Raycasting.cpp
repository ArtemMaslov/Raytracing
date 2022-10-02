#include "Raycasting.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

static bool CheckInSphere(const double radius, const Vector3& coord);

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Raycasting::Raycasting(int width, int height, double radius) :
	sceneWidth (width),
	sceneHeight(height),
	sphereRadius(radius),
	coordSys(Point2{width / 2.0, height / 2.0}, width, height, 20, 20),

	lightSource(20, 20, 20),
	viewPoint(0, 0, 20),

	colorMaterial{0.20, 0.15, 0.25},
	//colorMaterial{0.20, 0.20, 0.20},
	colorBackground{0.02, 0.07, 0.03},
	colorLightSource{1, 1, 1},
	colorLightAmbient{1, 1, 1},

	ambientCoef(0.1),
	diffusionCoef(3.8),
	glareCoef(0.1),
	glareCosExp(1.8)
{
	scene.create(coordSys.GetWidthP(), coordSys.GetHeightP());
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

static bool CheckInSphere(const double radius, const Vector3& coord)
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
			Vector3 coord = coordSys.PixelToCoord3(pixel);

			if (CheckInSphere(sphereRadius, coord))
			{
				coord.SetZ(sqrt(sphereRadius * sphereRadius - coord * coord));

				Vector3 lightRay = lightSource - coord;

				// Угол между нормалью к поверхности и направлением на источник.
				double cos_light_n = (lightRay * coord) / (lightRay.Length() * sphereRadius);

				// Свет среды.
				Color colorResult = ambientCoef * colorLightAmbient;

				// Часть тела попадает в область освещения источника, то есть не лежит в тени.
				if (cos_light_n > 0)
				{
					// Диффузное освещение.
					colorResult += cos_light_n * diffusionCoef * colorLightSource * colorMaterial;
				}
				
				Vector3 viewRay = viewPoint - coord;

				Vector3 reflectedLightRay{};
				Vector3::Mirror(lightRay, coord, reflectedLightRay);

				double cos_refl_view = (reflectedLightRay * viewRay) / (reflectedLightRay.Length() * viewRay.Length());

				if (cos_refl_view > 0)
				{
					colorResult += glareCoef * std::pow(cos_refl_view, glareCosExp) * colorLightSource;
				}

				scene.setPixel(pixel.x, pixel.y, colorResult.Convert());
			}
			else
			{
				scene.setPixel(pixel.x, pixel.y, colorBackground.Convert());
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
	//coordSys.DrawAxes(window, sf::Color(255, 255, 255));
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 