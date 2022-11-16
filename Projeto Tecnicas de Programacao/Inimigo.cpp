#include "Inimigo.h"
#include "Jogador.h"

#include <cmath>


Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador) :
	Personagem(pos, tam), relogio(), jogador(jogador)
{
	body.setFillColor(sf::Color::Red);
	Inicializa();
	srand(time(NULL));
	moveAle = rand() % 4;  //Movimento aleatorio caso nao saiba de nenhum jogador por perto
}

Inimigo::~Inimigo()
{
}

void Inimigo::Inimigo::Inicializa() {
	vel = sf::Vector2f(VEL_INIMIGO_X, VEL_INIMIGO_Y);
}

void Inimigo::segueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x <= posInimigo.x) {
		body.move(vel.x, 0.0f);
	}
	else {
		body.move(-vel.x, 0.0f);
	}
	if (posJogador.y <= posInimigo.y) {
		body.move(0.0f, vel.y);
	}
	else {
		body.move(0.0f, -vel.y);
	}
}

void Inimigo::movimentoAle()
{
	if (moveAle == 0) {
		body.move(vel.x, 0.0f);
	}
	else if (moveAle == 1) {
		body.move(-vel.x, 0.0f);
	}
	else if (moveAle == 2) {
		body.move(0.0f, vel.y);
	}
	else {
		body.move(0.0f, -vel.y);
	}

	float dt = relogio.getElapsedTime().asSeconds();
	if (dt >= 1.0f) {
		moveAle = rand() % 2; //2 -> so horizontal, 4 -> todas as direcoes
		relogio.restart();
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
}



