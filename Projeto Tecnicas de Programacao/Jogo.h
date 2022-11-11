#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include"Jogador.h"

class Jogo
{
private:
    // Gerenciador Gráfico
    NomeJogo::Gerenciador::GerenciadorGrafico* pGrafico;
    // Janela
    sf::RenderWindow window;
    // Jogador Principal
    Jogador jogador1;

public:
    Jogo();
    ~Jogo();
    // Executando o jogo
    void Executar();

};