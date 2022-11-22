#include "GerenciadorColisao.h"
#include <iostream>
using namespace std;

NomeJogo::Gerenciador::GerenciadorColisao::GerenciadorColisao(ListaEntidade* listaPersonagem) :
    listaPersonagem(listaPersonagem)
{

}

NomeJogo::Gerenciador::GerenciadorColisao::~GerenciadorColisao() {
    if (listaPersonagem) {
        delete(listaPersonagem);
    }
}

void NomeJogo::Gerenciador::GerenciadorColisao::verificaColisao(Entidade* entidade1, Entidade* entidade2) {
    // Posição das entidades no Jogo
    sf::Vector2f pos1 = entidade1->getCorpo().getPosition();
    sf::Vector2f pos2 = entidade2->getCorpo().getPosition();

    // Tamanho das entidades
    sf::Vector2f tam1 = entidade1->getCorpo().getSize();
    sf::Vector2f tam2 = entidade2->getCorpo().getSize();

    // Encontrando o centro do corpo
    sf::Vector2f centroEnt1 = sf::Vector2f(pos1.x + (tam1.x / 2), pos1.y + (tam1.y / 2));
    sf::Vector2f centroEnt2 = sf::Vector2f(pos2.x + (tam2.x / 2), pos2.y + (tam2.y / 2));
    // Distancia entre os centros
    sf::Vector2f distanciaCentros = sf::Vector2f(fabs(centroEnt1.x - centroEnt2.x), fabs(centroEnt1.y - centroEnt2.y));

    // Caso esteja ocorrendo colisão entre Jogador e Inimigo
    if ((distanciaCentros.x < tam1.x / 2 + tam2.x / 2) && (distanciaCentros.y < tam1.y / 2 + tam2.y / 2)) {
        entidade1->colisao(entidade2);
    }
}

void NomeJogo::Gerenciador::GerenciadorColisao::executar() {
    /*
        Calculando a distância entre todas as entidades do jogo para verificar se há colisão entre alguma
    */

    // Laço de repetição para passar por todos os personagens e verificar se há colisão entre Jogador e Inimigo
    for (int i = 0; i < listaPersonagem->lenEnt() - 1; i++) {
        Entidade* entidade1 = listaPersonagem->operator[](i);
        sf::Vector2f posAux(fabs(entidade1->getCorpo().getPosition().x), entidade1->getPosicao().y);
        if (entidade1->getCorpo().getPosition().x < 0.0) {
            entidade1->mudarPosicao(posAux);
        }
        for (int j = i + 1; j < listaPersonagem->lenEnt(); j++) {
            Entidade* entidade2 = listaPersonagem->operator[](j);
            // Calculando a distância entre as entidades
            verificaColisao(entidade1, entidade2);
            verificaColisao(entidade2, entidade1);
        }
    }
}