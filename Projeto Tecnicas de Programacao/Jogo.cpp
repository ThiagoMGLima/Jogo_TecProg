#include "Jogo.h"
#include "ListaEntidade.h"

Jogo::Jogo() :listaEnt(), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()), gerenciadorColisao(&listaEnt)
{
    InstaciarEntidades();
    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::InstaciarEntidades() {

    Jogador* jogador = new Jogador(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(50.0f, 50.0f));
    jogador->mudarPosicao(sf::Vector2f(0.0f, 550.0f));

    Inimigo* inimigo1 = new Inimigo(sf::Vector2f(100.0f, 450.0f), sf::Vector2f(50.0f, 50.0f), jogador);
    // Inimigo* inimigo2 = new Inimigo(sf::Vector2f(70.0f, 550.0f), sf::Vector2f(50.0f, 50.0f), jogador);

    Entidade* e1 = static_cast<Entidade*>(jogador);
    Entidade* e2 = static_cast<Entidade*>(inimigo1);
    // Entidade* e3 = static_cast<Entidade*>(inimigo2);

    listaEnt.pushEnt(e1);
    listaEnt.pushEnt(e2);
    // listaEnt.pushEnt(e3);
    pGerenciadorEvento->setJogador(jogador);
}

void Jogo::Executar()
{
    while (pGerenciadorGrafico->verificaJanelaAberta())
    {
        pGerenciadorEvento->executar();
        pGerenciadorGrafico->LimparJanela();

        listaEnt.executar(pGerenciadorGrafico->getWindow());
        gerenciadorColisao.executar();
        // Mostrando a janela
        pGerenciadorGrafico->mostrarNaTela();
    }

}