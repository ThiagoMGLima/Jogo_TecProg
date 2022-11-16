#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
    sf::Vector2f vel;
    sf::Vector2f velFinal;
    bool podeAndar;
    bool paraEsquerda;
    sf::Clock relogio;
    float dt;
public:
    Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
    Personagem();
    ~Personagem();
    void andar(const bool paraEsquerda);
    void parar(); // Quando a tecla de movimento é soltada
    void atualizarPosicao();
    virtual void atualizar() = 0;
};

