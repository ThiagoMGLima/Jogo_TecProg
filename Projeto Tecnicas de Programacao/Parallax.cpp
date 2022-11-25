#include "Parallax.h"


Parallax::Parallax(const Id::id id) :
    Ente(id), Anterior(pGerenciadorGrafico->getCamera().getCenter()),
    layers()
{

    //floresta escarlate
    /*
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscarlate/1.png", 0.0f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscarlate/2.png", 0.05f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscarlate/3.png", 0.1f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscarlate/4.png", 0.15f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscarlate/5.png", 0.2f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscarlate/6.png", 0.4f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscarlate/7.png", 0.6f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscarlate/8.png", 1.0f);
    */

    //Floresta escura
    /*
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscura/layers/1.png", 0.0f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscura/layers/2.png", 0.1f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscura/layers/3.png", 0.15f);
    //Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/FlorestaEscura/layers/4.png", 0.30f);
    */

    //Cidade escura
    /*
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/Cidade/Sprites/1.png", 0.0f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/Cidade/Sprites/2.png", 0.1f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/Cidade/Sprites/3.png", 0.15f);
    Parallax::addCamada("C:/Users/thiag/Desktop/teste/Test_Sfml_2/Test_Sfml_2/Layers/Cidade/Sprites/4.png", 0.20f);
    */

    //Montanha

    Parallax::addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Layers/Montanha/Montanha/layers/1.png", 0.0f);
    Parallax::addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Layers/Montanha/Montanha/layers/2.png", 0.005f);
    Parallax::addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Layers/Montanha/Montanha/layers/3.png", 0.01f);
    Parallax::addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Layers/Montanha/Montanha/layers/4.png", 0.10f);
    Parallax::addCamada("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Layers/Montanha/Montanha/layers/5.png", 0.15f);

}

Parallax::~Parallax() {
    for (int i = 0; i < layers.size(); i++) {
        Layer* layer = layers.at(i);
        if (layer) {
            delete(layer);
            layer = nullptr;
        }
    }
    layers.clear();
}

void Parallax::executar() {
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

void Parallax::atualizar()
{
}

void Parallax::draw() {
    for (int i = 0; i < layers.size(); i++) {
        Layer* layer = layers.at(i);
        layer->drawLayer(pGerenciadorGrafico->getWindow());
    }
}

void Parallax::addCamada(const char* caminhoTextura, const float vel) {
    Layer* layer = new Layer((sf::Vector2f)pGerenciadorGrafico->getWindow()->getSize(), pGerenciadorGrafico->CarregarTextura(caminhoTextura), vel);
    if (layer == nullptr) {
        std::cout << "ERRO::Jungle::Parallax::Fundo::nao foi possivel criar uma camada" << std::endl;
        exit(1);
    }
    layers.push_back(layer);
}