#include "Jogador.h"
#include <iostream>

void Jogador::Jogador::Inicializa() {
    vel = sf::Vector2f(0.1f, 0.1f);
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
    body.setSize(sf::Vector2f(tam));
    Inicializa();
}

Jogador::~Jogador()
{
}


void Jogador::Jogador::atualizar() {
    atualizarPosicao();
    relogio.restart();
}

void Jogador::colisao(Entidade* entidadeColidida)
{
    if (!noAr) {
        velFinal.y = -0.5f;
        noAr = true;
    }
}
