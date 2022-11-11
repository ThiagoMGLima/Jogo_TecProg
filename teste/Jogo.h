#pragma once

#include "Inimigo.h"
#include "Jogador.h"



    class Jogo
    {
    private:
        sf::RenderWindow window;

        std::vector <Personagem*> personagens;
    
    public:
        Jogo();
        ~Jogo();


        void Executar();

    };
