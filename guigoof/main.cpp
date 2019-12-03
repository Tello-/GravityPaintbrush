#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ball Painter", sf::Style::Fullscreen);
	sf::RectangleShape brick(sf::Vector2f{ 32,8 });
	sf::CircleShape shape(10.f);
	shape.setFillColor(sf::Color::Green);
	window.setFramerateLimit(60.f);
	std::vector<sf::CircleShape*> ballBag;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::LostFocus)
				window.requestFocus();
			
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			sf::CircleShape* newBall = new sf::CircleShape(shape);
			newBall->setPosition(sf::Vector2f{ sf::Mouse::getPosition() });
			ballBag.push_back(newBall);
			if (ballBag.size() > 100)
				ballBag.erase(ballBag.begin(), ballBag.begin() + 25);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		{
			shape.setFillColor(sf::Color::Magenta);
		}

		window.clear();
		for (auto c : ballBag)
		{
			window.draw(*c);
			c->move(sf::Vector2f{ 0.f, 5.f });
		}

		
		window.display();
		
	}

	return 0;
}