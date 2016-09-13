#pragma once
#include <SFML/Graphics.hpp>
class Star : public sf::Drawable
{
public:
	Star();
	~Star();
	void reinitialize();
	void update();
	const sf::Vector3f& location;
	const sf::Vector2f& screenLocation;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector3f _location;
private:
	sf::Vector2f _centreScreen;
	sf::Vector2f _screenLocation;
	sf::CircleShape _particle;
};

