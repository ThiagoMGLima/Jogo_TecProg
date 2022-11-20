#include "Inimigo.h"
#include "Jogador.h"
#include <cmath>


Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador) :
	Personagem(pos, tam), relogio(), jogador(jogador)
{
	body.setFillColor(sf::Color::Blue);
	body.setSize(tam);
	Inicializa();
	srand(time(NULL));
	moveAle = rand() % 4;  //Movimento aleatorio caso nao saiba de nenhum jogador por perto
	ID = "Inimigo";
}

Inimigo::~Inimigo()
{
}

void Inimigo::Inimigo::Inicializa() {
	vel = sf::Vector2f(VEL_INIMIGO_X, VEL_INIMIGO_Y);
}

void Inimigo::segueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	podeAndar = true;
	velFinal.x = 30.0f;
	if (posJogador.x <= posInimigo.x) {
		paraEsquerda = false;
		atualizarPosicao();
	}
	else {
		paraEsquerda = true;
		atualizarPosicao();
	}
}

void Inimigo::movimentoAle()
{
	podeAndar = true;
	velFinal.x = 30.0f;
	if (moveAle == 0) {
		paraEsquerda = false;
		atualizarPosicao();
	}
	else if (moveAle == 1) {
		paraEsquerda = true;
		atualizarPosicao();
	}

	float dt = relogio.getElapsedTime().asSeconds();
	if (dt >= 1.0f) {
		moveAle = rand() % 2; //2 -> so horizontal, 4 -> todas as direcoes
		relogio.restart();
	}
}

void Inimigo::colisao(Entidade* entidadeColidida)
{
	if (entidadeColidida->getID() == "Chao") {
		// Caso o Jogador esteja colidindo por cima, ou seja, caindo por cima pra plataforma
		if ((body.getPosition().y + body.getSize().y / 2) < entidadeColidida->getCorpo().getPosition().y) {
			body.setPosition(sf::Vector2f(body.getPosition().x, entidadeColidida->getCorpo().getPosition().y - body.getSize().y));
			noAr = false;
			velFinal.y = 0.0;
		}
	}
	else if (entidadeColidida->getID() == "Plataforma") {
		// Caso o Jogador esteja colidindo por cima, ou seja, caindo por cima pra plataforma
		if ((body.getPosition().y + body.getSize().y / 2) < entidadeColidida->getCorpo().getPosition().y) {
			printf("Inimigo colidiu plataforma\n");
			body.setPosition(sf::Vector2f(body.getPosition().x, entidadeColidida->getCorpo().getPosition().y - body.getSize().y));
			velFinal.y = 0.0;
			noAr = false;
		}
		else if ((body.getPosition().y + body.getSize().y / 2) > entidadeColidida->getCorpo().getPosition().y && 
			body.getPosition().y - body.getSize().y / 2 < entidadeColidida->getCorpo().getPosition().y) {
			velFinal.y = -0.3f;
			noAr = true;
			atualizarPosicao();
		}
		// Caso o jogador bata nas laterais ou na parte de baixo de alguma plataforma
		else {
			body.setPosition(posAnt);
			if (!paraEsquerda)
				body.move(sf::Vector2f(-0.1f, -0.1f));
			else
				body.move(sf::Vector2f(0.1f, 0.1f));
			velFinal.y = 0.3;
		}
	}
}

void Inimigo::atualizar() {

	sf::Vector2f posJogador = jogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = getCorpo().getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
		segueJogador(posInimigo, posJogador);
	}
	else {
		movimentoAle();
	}
	posAnt = body.getPosition();
}



