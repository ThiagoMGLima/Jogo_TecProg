#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "Chao.h"
#include "Plataforma.h"
#include "Espinhos.h"
#include "ListaEntidade.h"
#include "Parallax.h"

class Jogo
{
private:
    // Gerenciadores
    NomeJogo::Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
    NomeJogo::Gerenciador::GerenciadorEvento* pGerenciadorEvento;
    NomeJogo::Gerenciador::GerenciadorColisao gerenciadorColisao;
    Parallax parallax;

    ListaEntidade listaEnt;

public:
    Jogo();
    ~Jogo();
    void Executar();
    void InstaciarEntidades();

};
