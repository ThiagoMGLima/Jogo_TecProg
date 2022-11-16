#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "ListaEntidade.h"

class Jogo
{
private:
    // Gerenciadores
    NomeJogo::Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
    NomeJogo::Gerenciador::GerenciadorEvento* pGerenciadorEvento;

    ListaEntidade listaEnt;

public:
    Jogo();
    ~Jogo();
    void Executar();
    void InstaciarEntidades();

};