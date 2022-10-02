#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include <SFML/Window.hpp>

#include "Raycasting.hpp"
#include "RaycastingTest.hpp"

#include "../Vector/Vector2.hpp"

#include "../Animation/Iterator.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void TestSimple()
{
	const int width  = 400;
	const int height = 400;

	Raycasting raycasting(width, height);

	sf::RenderWindow window(sf::VideoMode(width, height), "RaycastingSimple");
	window.setFramerateLimit(30);

	while (window.isOpen())
	{
		sf::Event event = {};
		bool lock_click = false;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		raycasting.Draw(window);

		window.display();
	}
}

void TestDiffusionCoef()
{
    const int width  = 400;
    const int height = 400;

    Raycasting raycasting(width, height);

    sf::RenderWindow window(sf::VideoMode(width, height), "RaycastingDiffusion");
    window.setFramerateLimit(30);

    Iterator diffIter(0, 1, 0.01);

	while (window.isOpen())
	{
		sf::Event event = {};
		bool lock_click = false;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		raycasting.diffusionCoef = diffIter.GetNextValue(raycasting.diffusionCoef);
        printf("DiffusionCoef %.2lf\r", raycasting.diffusionCoef);
		raycasting.Draw(window);

		window.display();
	}
}

void TestLightCircle()
{
    const int width  = 400;
    const int height = 400;

    Raycasting raycasting(width, height);

    sf::RenderWindow window(sf::VideoMode(width, height), "Raycasting");
    window.setFramerateLimit(30);

	double phiStep = 0.1;

	while (window.isOpen())
	{
		sf::Event event = {};
		bool lock_click = false;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		Vector3* oldLight = &raycasting.lightSource;
		Vector2 newLight(oldLight->GetX(), oldLight->GetY());
		newLight.Rotate(phiStep);
		oldLight->SetValue(newLight.GetX(), newLight.GetY(), oldLight->GetZ());

		//printf("phi: %.2lf\r", phi);
		//phi += phiStep;

		raycasting.Draw(window);

		window.display();
	}
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 