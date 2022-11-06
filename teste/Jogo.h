#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Jogador.h"

class Jogo
{
private:
    sf::RenderWindow window;

    Jogador jogador1,jogador2;
   
public:
    Jogo();
    ~Jogo();

    void Executar();

};