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
    jogador->mudarPosicao(sf::Vector2f(0.0f, 450.0f));

    Inimigo* inimigo1 = new Inimigo(sf::Vector2f(100.0f, 450.0f), sf::Vector2f(50.0f, 50.0f), jogador);

    Chao* chao = new Chao("Chao", sf::Vector2f(800.0f, 100.0f), sf::Vector2f(0.0f, 500.0f));
    Plataforma* plataforma1 = new Plataforma("Plataforma", sf::Vector2f(180.0f, 400.0f), sf::Vector2f(100.0f, 20.0f));
    Plataforma* plataforma2 = new Plataforma("Plataforma", sf::Vector2f(380.0f, 430.0f), sf::Vector2f(100.0f, 20.0f));
    Plataforma* plataforma3 = new Plataforma("Plataforma", sf::Vector2f(580.0f, 460.0f), sf::Vector2f(100.0f, 20.0f));

    Entidade* e1 = static_cast<Entidade*>(jogador);
    Entidade* e2 = static_cast<Entidade*>(inimigo1);
    Entidade* e3 = static_cast<Entidade*>(plataforma1);
    Entidade* e4 = static_cast<Entidade*>(plataforma2);
    Entidade* e5 = static_cast<Entidade*>(plataforma3);
    Entidade* e6 = static_cast<Entidade*>(chao);

    listaEnt.pushEnt(e1);
    listaEnt.pushEnt(e2);
    listaEnt.pushEnt(e3);
    listaEnt.pushEnt(e4);
    listaEnt.pushEnt(e5);
    listaEnt.pushEnt(e6);
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