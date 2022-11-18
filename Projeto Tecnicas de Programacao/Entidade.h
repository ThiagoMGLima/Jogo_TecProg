#pragma once
#include "SFML/Graphics.hpp"
#include "Ente.h"

class Entidade: public Ente {

protected:
	// Corpo da entidade
	sf::RectangleShape body;
	sf::Vector2f posicao; // Posição no cenário
	sf::Vector2f tamanho; // Tamanho da Entidade
    // Posicao anterior para usar em situacoes de colisao
	sf::Vector2f posAnt;

public:
	Entidade();
	~Entidade();
	const sf::RectangleShape getCorpo();
	const sf::Vector2f getPosicao();
	const sf::Vector2f getPosAnt();
	const sf::Vector2f getTamanho();
	void mudarPosicao(sf::Vector2f posicao);
	virtual void colisao(Entidade* entidade) = 0;
};
