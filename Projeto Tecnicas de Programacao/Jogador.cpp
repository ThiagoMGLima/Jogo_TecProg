#include "Jogador.h"
#include <cmath>


Jogador::Jogador(const sf::Vector2f pos) :
    Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, Id::id::jogador)
{
    noAr = true;
    posAnt = pos;
    vida = 10;
    Inicializa();
}

void Jogador::Jogador::Inicializa()
{
    animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Jogador/Idle.png", "PARADO", 4, 0.15f, sf::Vector2f(8, 4));
    animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Jogador/Jump.png", "PULA", 2, 0.07f, sf::Vector2f(8, 4));
    animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Jogador/Run.png", "CORRE", 8, 0.18f, sf::Vector2f(8, 4));
    animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Jogador/Attack2.png", "ATACA", 4, 0.07f, sf::Vector2f(8, 4));
    animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Jogador/Fall.png", "CAI", 2, 0.07f, sf::Vector2f(8, 4));
    body.setOrigin(sf::Vector2f(tamanho.x / 2.25f, tamanho.y / 2.46f));
}


void Jogador::Pular()
{
    if (!noAr) {
        velFinal.y = -0.39f;
        noAr = true;
    }
}

Jogador::~Jogador()
{
}


void Jogador::Jogador::atualizar() {
    atualizarPosicao();
    atualizarAnimacao();
    relogio.restart();
    pGerenciadorGrafico->moveCamera(posicao);
}

void Jogador::colisao(Entidade* entidadeColidida)
{
    if (entidadeColidida->getID() == Id::id::Inimigo) {
        if ((body.getPosition().y + body.getSize().y / 2) < entidadeColidida->getCorpo().getPosition().y) {
            velFinal.y = -0.15;

        }
        else if (!paraEsquerda) {
            body.move(sf::Vector2f(-0.6f, -0.3f));
        }
        else {
            body.move(sf::Vector2f(0.6f, -0.3f));
        }
    }
    else if (entidadeColidida->getID() == Id::id::chao) {
        // Caso o Jogador esteja colidindo por cima, ou seja, caindo por cima pra plataforma
        if ((body.getPosition().y + body.getSize().y / 2) < entidadeColidida->getCorpo().getPosition().y) {
            body.setPosition(sf::Vector2f(body.getPosition().x, entidadeColidida->getCorpo().getPosition().y - body.getSize().y));
            noAr = false;
            velFinal.y = 0.0;
        }
    }
    else if (entidadeColidida->getID() == Id::id::plataforma) {
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
            velFinal.y = 0.3f;
        }
    }
}

void Jogador::atualizarAnimacao() {

    if (atacando) {
        animacao.atualizar(paraEsquerda, "ATACA");
    }
    else if (noAr && velFinal.y > 0.0f) {
        animacao.atualizar(paraEsquerda, "CAI");
    }
    else if (noAr) {
        animacao.atualizar(paraEsquerda, "PULA");
    }
    else if (podeAndar) {
        animacao.atualizar(paraEsquerda, "CORRE");
    }
    else {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}