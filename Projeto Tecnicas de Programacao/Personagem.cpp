#include "Personagem.h"

Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam) //contrutora com parametros posicao e tamanho
{
    body.setPosition(pos);
}

Personagem::Personagem()//constr sem parametros 
{
    podeAndar = false;
    paraEsquerda = false;
    dt = 0.0;
}

Personagem::~Personagem()
{

}
void Personagem::andar(const bool paraEsquerda)
{
    podeAndar = true;
    this->paraEsquerda = paraEsquerda; 
}

void Personagem::parar()
{
    podeAndar = false;
}

void Personagem::atualizarPosicao()
{
    float vel = 0.3;
    if (paraEsquerda) {
        vel *= -1;
    }
    body.move(vel, 0.0);
}


const sf::RectangleShape Personagem::getCorpo()
{
    return body;
}