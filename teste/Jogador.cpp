#include "Jogador.h"

Jogador::Jogador()
{
}

Jogador::~Jogador()
{
}

void Jogador::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        body.move(sf::Vector2f(0.1f, 0.f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        body.move(sf::Vector2f(0.f, 0.1f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        body.move(sf::Vector2f(-0.1f, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        body.move(sf::Vector2f(0.f, -0.1f));
    }

    window.clear();
    window.draw(shape);
    window.display();
}
