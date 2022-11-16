#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "Inimigo.h"
#include "Jogador.h"


class Jogo
{
private:
    // Gerenciadores
    NomeJogo::Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
    NomeJogo::Gerenciador::GerenciadorEvento* pGerenciadorEvento;

    std::vector <Personagem*> personagens;

public:
    Jogo();
    ~Jogo();
    void Executar();

};