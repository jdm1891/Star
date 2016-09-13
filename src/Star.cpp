#include "Star.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <ctime>


Star::Star() : location(_location),  screenLocation(_screenLocation)
{
	_particle.setRadius(1);
	_centreScreen.x = sf::VideoMode::getDesktopMode().width / 2;
	_centreScreen.y = sf::VideoMode::getDesktopMode().height / 2;
	_particle.setOrigin(_particle.getOrigin().x + _particle.getRadius(), _particle.getOrigin().y + _particle.getRadius());
	reinitialize();
}


Star::~Star()
{
}

void Star::reinitialize()
{	
	static int count = 0;
	_particle.setFillColor(sf::Color(255,255,255,0));
	static std::default_random_engine engine;
	engine.seed(time(nullptr)*count);
	_particle.setRadius(1);
	static std::uniform_int_distribution<int> distribution_xy(-5000, 5000);
	static std::uniform_int_distribution<int> distribution_z(100, 1000);
	_location.x = distribution_xy(engine);
	_location.y = distribution_xy(engine);
	_location.z = distribution_z(engine);
	++count;
}

void Star::update()
{
	if (_particle.getFillColor().a < 255)
	{
		_particle.setFillColor(sf::Color(255, 255, 255, _particle.getFillColor().a + 1));
	}
	_location.z -= 1;
	_screenLocation.x = _location.x / _location.z * 100 + _centreScreen.x;
	_screenLocation.y = _location.y / _location.z * 100 + _centreScreen.y;
	_particle.setPosition(_screenLocation.x, screenLocation.y);
	_particle.setRadius(_particle.getRadius()+1*(1/_location.z));
}

void Star::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_particle, states);
}
