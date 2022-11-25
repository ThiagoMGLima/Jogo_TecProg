#pragma once
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"

class Imagem
{
private:
    NomeJogo::Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
    sf::Texture textura;
    sf::IntRect tamanho;
    const sf::Vector2f escala;
    const unsigned int qtdImagem;
    unsigned int imgAtual;
    const float Troca;
    float Tempo;
public:
    Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float Troca, const sf::Vector2f escala);
    ~Imagem();
    void atualizar(const bool paraEsquerda, const float dt);
    void resetar();
    const sf::IntRect getLen() const;
    const sf::Texture* getTextura() const;
    const sf::Vector2f getEscala() const;
};