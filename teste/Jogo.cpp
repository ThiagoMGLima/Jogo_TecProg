#include "Jogo.h"

Jogo::Jogo():
	window(sf::VideoMode(800, 800), "Jogo"),personagens() {
    
    Jogador* jogador = new Jogador(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(50.0f, 50.0f));
    Inimigo* inimigo = new Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f),jogador);
    
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
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Fecha o jogo quando é pressionado o Esc(Escape) ou o X da janela
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear();
        for (int i = 0; i < personagens.size(); i++) {
            personagens.at(i)->move();
            window.draw(personagens.at(i)->getCorpo());
        }
        window.display();
        personagens.clear();
    }
}
