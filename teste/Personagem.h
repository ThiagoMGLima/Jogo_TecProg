#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Personagem
{
protected:
	sf::RectangleShape body;
	sf::Vector2f vel;
public:
	Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
	Personagem();
	~Personagem();
	virtual void move() = 0;
	const sf::RectangleShape getCorpo();
};

