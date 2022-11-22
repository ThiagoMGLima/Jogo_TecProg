#include "Parallax.h"


NomeJogo::Parallax::Parallax::Parallax(const Id::id id) :
    Ente(id), Anterior(pGerenciadorGrafico->getCamera().getCenter()),
    layers()
{

    //floresta escarlate
    addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao\Projeto Tecnicas de Programacao/Layers/1.png", 0.0f);
    addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Layers/2.png", 0.05f);
    addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Layers/3.png", 0.1f);
    addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Layers/4.png", 0.15f);
    addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Layers/5.png", 0.2f);
    addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Layers/6.png", 0.4f);
    addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Layers/7.png", 0.6f);
    addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Layers/8.png", 1.0f);

}

NomeJogo::Parallax::Parallax::~Parallax() {
    for (int i = 0; i < layers.size(); i++) {
        Layer* layer = layers.at(i);
        if (layer) {
            delete(layer);
            layer = nullptr;
        }
    }
    layers.clear();
}

void NomeJogo::Parallax::Parallax::executar() {
    sf::Vector2f posCamera = pGerenciadorGrafico->getCamera().getCenter();
    sf::Vector2f ds = posCamera - Anterior;
    Anterior = posCamera;
    if (ds.x != 0.0f) {
        ds.x *= 0.5f;
        for (int i = 0; i < layers.size(); i++) {
            layers.at(i)->atualizar(ds, posCamera);
        }
    }
    draw();
}

void NomeJogo::Parallax::Parallax::draw() {
    for (int i = 0; i < layers.size(); i++) {
        Layer* layer = layers.at(i);
        layer->drawLayer(pGerenciadorGrafico->getWindow());
    }
}

void NomeJogo::Parallax::Parallax::addCamada(const char* caminhoTextura, const float vel) {
    Layer* layer = new Layer((sf::Vector2f)pGerenciadorGrafico->getWindow()->getSize(), pGerenciadorGrafico->CarregarTextura(caminhoTextura), vel);
    if (layer == nullptr) {
        std::cout << "ERRO::Jungle::Parallax::Fundo::nao foi possivel criar uma camada" << std::endl;
        exit(1);
    }
    layers.push_back(layer);
}