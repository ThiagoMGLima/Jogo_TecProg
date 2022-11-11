#pragma once
#include "GerenciadorGrafico.h"
#include "Inimigo.h"
#include "Jogador.h"
#include <iostream>
using namespace std;

class Jogo
{
private:
    NomeJogo::Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;

    std::vector <Personagem*> personagens;
    
public:
    Jogo();
    ~Jogo();
    void Executar();

};
