#pragma once
#include "SFML/Graphics.hpp"
#include "Ente.h"
#include <string>

class Entidade : public Ente {

protected:
	sf::RectangleShape body;// Corpo da entidade
	sf::Vector2f posicao; // Posição no cenário
	sf::Vector2f tamanho; // Tamanho da Entidade

	// Posicao anterior para usar em situacoes de colisao
	sf::Vector2f posAnt;

public:
	Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const Id::id id);
	~Entidade();
	const sf::RectangleShape getCorpo();
	const sf::Vector2f getPosicao();
	const sf::Vector2f getPosAnt();
	const sf::Vector2f getTamanho();
	void mudarPosicao(sf::Vector2f posicao);
	virtual void atualizar() = 0;
	virtual void colisao(Entidade* entidade) = 0;
	void desenha();
};