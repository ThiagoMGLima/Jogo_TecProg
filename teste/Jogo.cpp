#include "Jogo.h"

Jogo::Jogo():
	window(sf::VideoMode(1200, 800), "Jogo"){
    jogador1.setWindow(&window);
    Executar();

}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        jogador1.move();
        window.clear();
        jogador1.draw();
        window.display();
    }
}
