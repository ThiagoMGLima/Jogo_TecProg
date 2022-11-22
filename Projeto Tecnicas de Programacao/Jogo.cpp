#include "Jogo.h"
#include "ListaEntidade.h"
#include "Ente.h"

Jogo::Jogo() :
    listaEnt(),
    pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
    pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()),
    gerenciadorColisao(&listaEnt)
{
    if (pGerenciadorGrafico == nullptr) {
        std::cout << "ERROR::NomeJogo::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }
    if (pGerenciadorEvento == nullptr) {
        std::cout << "ERROR::NomeJogo::Principal nao foi possivel criar um GerenciadorEvento" << std::endl;
        exit(1);
    }

    InstaciarEntidades();
    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::InstaciarEntidades() {
    //cria Personagens na pos (x,y)
    Jogador* jogador = new Jogador(sf::Vector2f(0.0f, 450.0f));

    Inimigo* inimigo1 = new Inimigo(sf::Vector2f(220, 350.0f), sf::Vector2f(40.0f, 60.0f), jogador, Id::id::Inimigo);
    Inimigo* inimigo2 = new Inimigo(sf::Vector2f(560, 300.0f), sf::Vector2f(40.0f, 60.0f), jogador, Id::id::Inimigo);

    //cria terrenos (ID,tam,posicao,textura)
    Chao* chao = new Chao(sf::Vector2f(1200.0f, 100.0f), sf::Vector2f(0.0f, 600.0f), "C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Plataforma/Chao.png");

    Plataforma* plataforma1 = new Plataforma(Id::id::plataforma, sf::Vector2f(180.0f, 400.0f), sf::Vector2f(100.0f, 20.0f), "C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Plataforma/Plataforma.png");
    Plataforma* plataforma2 = new Plataforma(Id::id::plataforma, sf::Vector2f(380.0f, 430.0f), sf::Vector2f(100.0f, 20.0f), "C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Plataforma/pedra.jpg");
    Plataforma* plataforma3 = new Plataforma(Id::id::plataforma, sf::Vector2f(580.0f, 460.0f), sf::Vector2f(100.0f, 20.0f), "C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Plataforma/pedra.jpg");
    Plataforma* plataforma4 = new Plataforma(Id::id::plataforma, sf::Vector2f(-300.0f, 0.0f), sf::Vector2f(400.0f, 130.0f), "C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Pasta/image.png");

    Entidade* e1 = static_cast<Entidade*>(jogador);
    Entidade* e2 = static_cast<Entidade*>(inimigo1);
    Entidade* e3 = static_cast<Entidade*>(inimigo2);
    Entidade* e4 = static_cast<Entidade*>(plataforma1);
    Entidade* e5 = static_cast<Entidade*>(plataforma2);
    Entidade* e6 = static_cast<Entidade*>(plataforma3);
    Entidade* e7 = static_cast<Entidade*>(chao);
    Entidade* e8 = static_cast<Entidade*>(plataforma4);

    listaEnt.pushEnt(e1);
    listaEnt.pushEnt(e2);
    listaEnt.pushEnt(e3);
    listaEnt.pushEnt(e4);
    listaEnt.pushEnt(e5);
    listaEnt.pushEnt(e6);
    listaEnt.pushEnt(e7);
    listaEnt.pushEnt(e8);
    pGerenciadorEvento->setJogador(jogador);
}

void Jogo::Executar()
{
    while (pGerenciadorGrafico->verificaJanelaAberta())
    {
        //gerencia eventos
        pGerenciadorEvento->executar();

        //Limpa janela
        pGerenciadorGrafico->LimparJanela();

        //Executa entidades
        listaEnt.executar(pGerenciadorGrafico->getWindow());
        //Executa Ger de Colisao
        gerenciadorColisao.executar();
        // Mostrando a janela
        pGerenciadorGrafico->mostrarNaTela();
    }

}