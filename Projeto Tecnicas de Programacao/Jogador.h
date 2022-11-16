#pragma once
#include "Personagem.h"

class Jogador :public Personagem {

private:
	bool ar;
	void Inicializa();
public:
	Jogador(const sf::RectangleShape body);
	Jogador(sf::Vector2f pos, sf::Vector2f tam);
	Jogador();
	~Jogador();
	void atualizar();
};