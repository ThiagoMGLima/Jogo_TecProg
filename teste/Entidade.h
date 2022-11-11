#pragma once
#include "SFML/Graphics.hpp"


class Entidade {

protected:
	sf::RectangleShape body;
	sf::RenderWindow *window;

public:
	Entidade();
	~Entidade();

	void setWindow(sf::RenderWindow* window) {
		this->window = window;
	}
	
	const sf::RectangleShape getCorpo();

	void draw() {
		window->draw(body);
	}
};
