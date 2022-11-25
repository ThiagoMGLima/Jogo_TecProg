#include "Personagem.h"



Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const Id::id id) :
    Entidade(pos, tam, id), podeAndar(false), paraEsquerda(false), relogio(), dt(0.0f), velFinal(sf::Vector2f(0.0f, 0.0f)), animacao(&body), atacando(false)
    //contrutora com parametros posicao e tamanho
{
    podePular = false;
    noAr = false;
    posAnt = posicao;
    this->vida = vida;
    vida = 6;

}



Personagem::~Personagem()
{

}
void Personagem::andar(const bool paraEsquerda)
{
    podeAndar = true;
    velFinal.x = 200;
    this->paraEsquerda = paraEsquerda;
}

void Personagem::parar()
{
    podeAndar = false;
    atacando = false;
}


void Personagem::cair()
{
    podePular = false;
}

void Personagem::atacar(const bool atacando)
{
    podeAndar = false;
    this->atacando = atacando;
}

int Personagem::getVida()
{
    return vida;
}

void Personagem::setVida(int vida) {
    this->vida = vida;
}

bool Personagem::estaAtacando()
{
    return atacando;
}

void Personagem::atualizarPosicao()
{
    dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    sf::Vector2f ds(0.0f, 0.0f);

    //move na horizontal
    if (podeAndar) {
        ds.x = velFinal.x * dt;
        if (paraEsquerda) {
            ds.x *= -1;
        }
    }

    //sofre o efeito da gravidade
    velFinal.y += dt * 1.0f;
    ds.y = velFinal.y * 1.0f;
    posAnt = body.getPosition();
    mudarPosicao(sf::Vector2f(body.getPosition().x + ds.x, body.getPosition().y + ds.y));


    //desenha na janela
    desenha();
}

void Personagem::atualizarAnimacao() {
    if (podeAndar) {
        animacao.atualizar(paraEsquerda, "ANDA");
    }
    else {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}
