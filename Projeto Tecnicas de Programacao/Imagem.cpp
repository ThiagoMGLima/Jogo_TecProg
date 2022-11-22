#include "Imagem.h"

Imagem::Imagem(const char* caminhoTextura, unsigned int qtdImagem, const float Troca, const sf::Vector2f escala) :
    pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
    qtdImagem(qtdImagem), Troca(Troca),
    Tempo(0.0f), tamanho(0, 0, 0, 0), imgAtual(0),
    textura(pGerenciadorGrafico->CarregarTextura(caminhoTextura)),
    escala(escala)
{
    tamanho.width = textura.getSize().x / (float)qtdImagem;
    tamanho.height = textura.getSize().y;
}

Imagem::~Imagem() {

}

void Imagem::atualizar(const bool paraEsquerda, const float dt) {
    Tempo += dt;
    if (Tempo >= Troca) {
        Tempo -= Troca;
        imgAtual++;
        if (imgAtual >= qtdImagem) {
            imgAtual = 0;
        }
    }
    if (paraEsquerda) {
        tamanho.left = (imgAtual + 1) * abs(tamanho.width);
        tamanho.width = -abs(tamanho.width);
    }
    else {
        tamanho.left = imgAtual * tamanho.width;
        tamanho.width = abs(tamanho.width);
    }
}

void Imagem::resetar() {
    imgAtual = 0;
    Tempo = 0.0f;
}

const sf::IntRect Imagem::getLen() const {
    return tamanho;
}

const sf::Texture* Imagem::getTextura() const {
    return (&textura);  //endereco da textura
}

const sf::Vector2f Imagem::getEscala() const {

    return escala;
}