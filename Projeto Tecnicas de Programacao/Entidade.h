#pragma once
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"

class Entidade {

protected:
	// Gerenciador Grafico
	NomeJogo::Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
	// Corpo da entidade
	sf::RectangleShape body;
	sf::Vector2f posicao; // Posição no cenário
	sf::Vector2f tamanho; // Tamanho da Entidade

public:
	Entidade();
	~Entidade();
	const sf::RectangleShape getCorpo();
	const sf::Vector2f getPosicao();
	const sf::Vector2f getTamanho();
	void mudarPosicao(sf::Vector2f posicao);
	void desenhar();
	virtual void atualizar() = 0;
	virtual void colisao(Entidade* entidade) = 0;
};
