#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
	sf::Vector2f vel;
public:
	Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
	Personagem();
	~Personagem();
	virtual void move() = 0;
};

