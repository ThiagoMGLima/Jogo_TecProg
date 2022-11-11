#include "Jogo.h"

Jogo::Jogo() :
    window(sf::VideoMode(1200, 800), "Jogo") {
    jogador1.setWindow(&window);
    Executar();

}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (pGrafico->verificaJanelaAberta(&window))
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGrafico->FechaJanela(&window);
        }
        // Jogador se move
        jogador1.move();
        // Limpando a janela
        pGrafico->LimparJanela(&window);
        // Desenhando o jogador na janela
        jogador1.desenhaNaTela();
        // Mostrando a janela
        pGrafico->mostrarNaTela(&window);
    }
}
