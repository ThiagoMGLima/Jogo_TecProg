#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Entidade.h"
#include "Animacao.h"

class Personagem : public Entidade
{
protected:
    sf::Vector2f vel;
    sf::Vector2f velFinal;
    Animacao animacao;
    bool podeAndar;
    bool paraEsquerda;
    // Se personagem pode realizar pulo
    bool podePular;
    // Se personagem ja está performando pulo
    bool noAr;
    sf::Clock relogio;
    float dt;
    bool atacando;
    float vida;
    float tempoAtaque;
    float tempoMorte;
    virtual void atualizarAnimacao();
public:
    Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const Id::id id);
    ~Personagem();
    void andar(const bool paraEsquerda);
    void parar(); // Quando a tecla de movimento é soltada
    void cair();
    void atacar(const bool atacando);
    int getVida();
    void setVida(int vida);
    void atualizarPosicao();
    bool estaAtacando();
    virtual void atualizar() = 0;

};
