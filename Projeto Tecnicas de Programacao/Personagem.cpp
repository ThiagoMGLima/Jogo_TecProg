#include "Personagem.h"

Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam) //contrutora com parametros posicao e tamanho
{
    body.setPosition(pos);
}

Personagem::Personagem()//constr sem parametros 
{
}

Personagem::~Personagem()
{

};

const sf::RectangleShape Personagem::getCorpo()
{
    return body;
}