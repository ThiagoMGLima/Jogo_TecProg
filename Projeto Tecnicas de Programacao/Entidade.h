#pragma once
#include "SFML/Graphics.hpp"


class Entidade {

protected:
	sf::RectangleShape body;

public:
	Entidade();
	~Entidade();

	const sf::RectangleShape getCorpo();
	virtual void atualizar() = 0;
};
