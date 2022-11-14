#include "Jogo.h"

Jogo::Jogo() :personagens(), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico())
{


    Jogador* jogador = new Jogador(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(50.0f, 50.0f));
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
        sf::Event event;
        if (pGerenciadorGrafico->getWindow()->pollEvent(event))
        {
            //Fecha o jogo quando é pressionado o Esc(Escape) ou o X da janela
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                pGerenciadorGrafico->FechaJanela();
        }



        for (int i = 0; i < personagens.size(); i++) {
            // Jogador se move
            personagens.at(i)->move();

            // Desenhando o Inimigo na janela
            pGerenciadorGrafico->desenhaNaTela(personagens.at(i)->getCorpo());
        }

        // Mostrando a janela
        pGerenciadorGrafico->mostrarNaTela();

        // Limpando a janela
        pGerenciadorGrafico->LimparJanela();
    }
}
