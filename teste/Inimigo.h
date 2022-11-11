#pragma once
#include <time.h>

#include "Personagem.h"
#include "Jogador.h"

#include <cmath>

#define VEL_INIMIGO_X  0.025f
#define VEL_INIMIGO_Y  0.025f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

class Inimigo :
    public Personagem{
private:
    Jogador * jogador;
    sf::Clock relogio;
    short moveAle;
    void Inicializa();
public:
    Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador);
    ~Inimigo();
    void segueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
    void movimentoAle();
    void move();
};

