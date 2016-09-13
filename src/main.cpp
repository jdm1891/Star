#include <SFML\Graphics.hpp>
#include <vector>
#include "Star.h"
#include <ctime>
#include <iostream>
#define NUMBER_OF_STARS 1000
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode()), "Stars", sf::Style::Fullscreen, settings);
	window.setFramerateLimit(60);

	std::vector<Star> stars(NUMBER_OF_STARS);
	window.clear(sf::Color::Black);
	while(true)
	{
		for (Star& star : stars)
		{
			star.update();
			window.draw(star);
			if (star.screenLocation.x > sf::VideoMode::getDesktopMode().width+20 || star.screenLocation.x < -20 || star.screenLocation.y > sf::VideoMode::getDesktopMode().height +20 || star.screenLocation.y < -20)
			{
				star.reinitialize();
			}
			
		}
		window.display();
		window.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			exit(0);
		}
	}
	return 0;
}