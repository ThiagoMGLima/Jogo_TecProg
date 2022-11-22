#include "Animacao.h"

Animacao::Animacao(sf::RectangleShape* body) :
    mapImagem(), relogio(), corpo(body), imgAtual("")
{
}

Animacao::~Animacao() {
    std::map<std::string, Imagem*>::iterator it = mapImagem.begin();

    while (it != mapImagem.end()) {
        if (it->second) {
            delete(it->second);
            it->second = nullptr;
        }
        it++;
    }
    mapImagem.clear();
}

void Animacao::atualizar(const bool paraEsquerda, std::string imgAtual) {
    if (this->imgAtual != imgAtual) {
        if (this->imgAtual != "") { //analiza se necessita de troca de img
            mapImagem[this->imgAtual]->resetar();
        }
        this->imgAtual = imgAtual; //atualizando estado da animacao
    }
    float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart(); //reseta o temp para a outra animacao

    Imagem* img = mapImagem[this->imgAtual];
    sf::Vector2f tamCorpo = corpo->getSize();
    sf::Vector2f escala = img->getEscala();

    //atualiza img e seus atributos
    img->atualizar(paraEsquerda, dt);
    corpo->setTextureRect(img->getLen());
    corpo->setTexture(img->getTextura());
    corpo->setScale(escala.x, escala.y);
}

void Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempo, const sf::Vector2f escala)
{

    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempo, escala);

    mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}


