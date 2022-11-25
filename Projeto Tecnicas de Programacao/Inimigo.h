#pragma once
#include <time.h>

#include "Personagem.h"
#include "Jogador.h"

#include <cmath>

#define VEL_INIMIGO 17.0f

#define RAIO_PERSEGUIR_X 250.0f
#define RAIO_PERSEGUIR_Y 250.0f

class Inimigo :
    public Personagem {
private:
    Jogador* jogador;
    short moveAle;
    void Inicializa();
    sf::Clock relogio;

public:
    void movimentoAle();
    Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador, const Id::id id);
    ~Inimigo();
    void segueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
    void atualizaAnimacao();
    void colisao(Entidade* entidadeColidida);
    virtual void atualizar();
};