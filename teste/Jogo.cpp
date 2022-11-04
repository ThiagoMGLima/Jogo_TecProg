#include "Jogo.h"

Jogo::Jogo():
	window(sf::VideoMode(400, 400), "Jogo"){

	shape.setFillColor(sf::Color::Green);
	
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
    }
}
