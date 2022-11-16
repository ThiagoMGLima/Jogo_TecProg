#include "Jogador.h"
#include <iostream>

void Jogador::Jogador::Inicializa() {
    vel = sf::Vector2f(0.1f, 0.1f);
    ar = false;
}

Jogador::Jogador() //sem parametros
{
    Inicializa();
}



Jogador::Jogador(const sf::RectangleShape body) //contr com parametro corpo (body)
{
    Inicializa();
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam)
{
    body.setFillColor(sf::Color::Red);
    Inicializa();
}

Jogador::~Jogador()
{
}


void Jogador::Jogador::atualizar() {
    if (podeAndar) {
        atualizarPosicao();
    }
    relogio.restart();
}