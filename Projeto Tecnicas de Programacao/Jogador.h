#pragma once
#include "Personagem.h"

#define VELOCIDADE_JOGADOR 350.0f
#define TAMANHO_JOGADOR_X 40.0f
#define TAMANHO_JOGADOR_Y 60.0f

class Jogador :public Personagem {

private:
	void Inicializa();
public:
	Jogador(sf::Vector2f pos);
	~Jogador();
	void atualizar(); //certo
	void Pular();
	void atualizarAnimacao(); //certo
	void colisao(Entidade* entidadeColidida);
};