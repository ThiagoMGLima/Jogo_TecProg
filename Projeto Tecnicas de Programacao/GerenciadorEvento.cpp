#include "GerenciadorEvento.h"

NomeJogo::Gerenciador::GerenciadorEvento* NomeJogo::Gerenciador::GerenciadorEvento::pEvento = nullptr;

NomeJogo::Gerenciador::GerenciadorEvento::GerenciadorEvento() :
    pGrafico(pGrafico->getGerenciadorGrafico())
{
}

NomeJogo::Gerenciador::GerenciadorEvento::~GerenciadorEvento() {

}

NomeJogo::Gerenciador::GerenciadorEvento* NomeJogo::Gerenciador::GerenciadorEvento::getGerenciadorEvento() {
    if (pEvento == nullptr) {
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}
void NomeJogo::Gerenciador::GerenciadorEvento::setJogador(Jogador* pJogador) {
    this->pJogador = pJogador;
}

void NomeJogo::Gerenciador::GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla) {
    if (tecla == sf::Keyboard::A) {
        pJogador->andar(true);
    }
    else if (tecla == sf::Keyboard::D) {
        pJogador->andar(false);
    }
    else if (tecla == sf::Keyboard::W) {
        pJogador->pular();
    }
    else if (tecla == sf::Keyboard::Escape) {
        pGrafico->FechaJanela();
    }
}

void NomeJogo::Gerenciador::GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla) {
    // Condicional para ler a tecla solta
    if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D) {
        pJogador->parar();
    }
}

void NomeJogo::Gerenciador::GerenciadorEvento::executar() {
    sf::Event evento;
    while (pGrafico->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::KeyPressed) {
            verificaTeclaPressionada(evento.key.code);
        }
        else if (evento.type == sf::Event::KeyReleased) {
            verificaTeclaSolta(evento.key.code);
        }
        else if (evento.type == sf::Event::Closed) {
            pGrafico->FechaJanela();
        }
    }
}