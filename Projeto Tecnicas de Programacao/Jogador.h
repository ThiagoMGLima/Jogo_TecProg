#pragma once
#include "Personagem.h"
#include "SFML/Graphics.hpp"

class Jogador :public Personagem {

private:
	void Inicializa();
public:
	Jogador();
	Jogador(const sf::RectangleShape body);
	Jogador(sf::Vector2f pos, sf::Vector2f tam);
	~Jogador();
	void atualizar();
	void colisao(Entidade* entidadeColidida);
};