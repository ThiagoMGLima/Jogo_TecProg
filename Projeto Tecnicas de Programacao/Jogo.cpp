#include "Jogo.h"

Jogo::Jogo() :personagens(), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento())
{


    Jogador* jogador = new Jogador(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(50.0f, 50.0f));
    pGerenciadorEvento->setJogador(jogador);
    Inimigo* inimigo = new Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f), jogador);

    Personagem* p1 = static_cast<Personagem*>(jogador);
    Personagem* p2 = static_cast<Personagem*>(inimigo);

    personagens.push_back(p1);
    personagens.push_back(p2);

    Executar();
}


Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (pGerenciadorGrafico->verificaJanelaAberta())
    {
        pGerenciadorEvento->executar();
        // Limpando a janela
        pGerenciadorGrafico->LimparJanela();
        for (int i = 0; i < personagens.size(); i++) {
            // Jogador se move
            personagens.at(i)->atualizar();

            // Desenhando o Inimigo na janela
            pGerenciadorGrafico->desenhaNaTela(personagens.at(i)->getCorpo());
        }

        // Mostrando a janela
        pGerenciadorGrafico->mostrarNaTela();
    }
}
