#include "Personagem.h"

Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam) //contrutora com parametros posicao e tamanho
{
    body.setPosition(pos);
}

Personagem::Personagem()//constr sem parametros 
{
    podeAndar = false;
    paraEsquerda = false;
    podePular = false;
    noAr = false;
    velFinal.x = 0.0;
    velFinal.y = 0.0;
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

void Personagem::pular()
{
    if (!noAr) {
        velFinal.y = - 0.5f;
        noAr = true;
    }
}

void Personagem::cair()
{
    podePular = false;
}

void Personagem::atualizarPosicao()
{
    dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    // printf("Valor Dt: %f\n", dt);
    // printf("Velocidade Y: %f\n", velFinal.y);
    sf::Vector2f ds(0.0f, 0.0f);

    //move na horizontal
    if (podeAndar) {
        ds.x = 100 * dt;
        if (paraEsquerda) {
            ds.x *= -1;
        }
    }
    if ((body.getPosition().y) > 550.0f) {
        noAr = false;
    }
    if (noAr == true) {
        //sofre o efeito da gravidade
        velFinal.y += dt * 1.0f;
        ds.y = velFinal.y * 1.0f;
        mudarPosicao(sf::Vector2f(body.getPosition().x + ds.x, body.getPosition().y + ds.y));
    }
    else {
        mudarPosicao(sf::Vector2f(body.getPosition().x + ds.x, 550.0f));
    }

    //desenha na janela
    desenhar();
}