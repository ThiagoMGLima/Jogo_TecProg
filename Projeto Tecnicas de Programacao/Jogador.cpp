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
    posAnt = pos;
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
    if (entidadeColidida->getID() == "Inimigo") {
        if (!paraEsquerda) {
            body.move(sf::Vector2f(-0.6f, -0.3f));
            entidadeColidida->mudarPosicao(entidadeColidida->getPosAnt());
        }
        else {
            body.move(sf::Vector2f(0.6f, -0.3f));
            entidadeColidida->mudarPosicao(entidadeColidida->getPosAnt());
        }
    }
    else if (entidadeColidida->getID() == "Chao") {
        // Caso o Jogador esteja colidindo por cima, ou seja, caindo por cima pra plataforma
        if ((body.getPosition().y + body.getSize().y / 2) < entidadeColidida->getCorpo().getPosition().y) {
            body.setPosition(sf::Vector2f(body.getPosition().x, entidadeColidida->getCorpo().getPosition().y - body.getSize().y));
            noAr = false;
            velFinal.y = 0.0;
        }
    }
    else if (entidadeColidida->getID() == "Plataforma") {
        // Caso o Jogador esteja colidindo por cima, ou seja, caindo por cima pra plataforma
        if ((body.getPosition().y + body.getSize().y / 2) < entidadeColidida->getCorpo().getPosition().y) {
            body.setPosition(sf::Vector2f(body.getPosition().x, entidadeColidida->getCorpo().getPosition().y - body.getSize().y));
            velFinal.y = 0.0;
            noAr = false;
        }
        // Caso o jogador bata nas laterais ou na parte de baixo de alguma plataforma
        else {
            body.setPosition(posAnt);
            if (!paraEsquerda)
                body.move(sf::Vector2f(-0.1f, -0.1f));
            else
                body.move(sf::Vector2f(0.1f, 0.1f));
            velFinal.y = 0.3;
        }
    }
}
