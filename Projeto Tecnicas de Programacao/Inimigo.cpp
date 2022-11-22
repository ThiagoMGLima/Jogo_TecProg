#include "Inimigo.h"
#include "Jogador.h"
#include <cmath>


Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador, const Id::id id) :
	Personagem(pos, tam, VEL_INIMIGO, Id::id::Inimigo), jogador(jogador), relogio()
{
	Inicializa();

	//Movimento Aleatorio
	srand((int)time(NULL));
	moveAle = rand() % 3;
	tempoAtaque = 0.0;

}

Inimigo::~Inimigo()
{
}

void Inimigo::Inimigo::Inicializa() {
	animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Inimigo/Skeleton/Idle.png", "PARADO", 4, 0.15f, sf::Vector2f(7.5, 3.5));
	animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Inimigo/Skeleton/Idle.png", "PULA", 4, 0.07f, sf::Vector2f(7.5, 3.5));
	animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Inimigo/Skeleton/Walk.png", "CORRE", 4, 0.18f, sf::Vector2f(7.5, 3.5));
	animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Inimigo/Skeleton/Attack3.png", "ATACA", 6, 0.18f, sf::Vector2f(7.5, 3.5));
	animacao.addAnimacao("C:/Users/Jooj/Documents/Faculdade/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Projeto Tecnicas de Programacao/Inimigo/Skeleton/Idle.png", "CAI", 4, 0.07f, sf::Vector2f(7.5, 3.5));
	body.setOrigin(sf::Vector2f(tamanho.x / 2.25f, tamanho.y / 2.55f));
}

void Inimigo::segueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	podeAndar = true;
	velFinal.x = VEL_INIMIGO + 30.0f; //velocidade do inimigo mais rapida enquanto segue jogador
	if (posJogador.x <= posInimigo.x) {
		paraEsquerda = false;
		atualizarPosicao();
		atualizaAnimacao();
	}
	else {
		paraEsquerda = true;
		atualizarPosicao();
		atualizaAnimacao();

	}
}

void Inimigo::movimentoAle()
{
	velFinal.x = VEL_INIMIGO;
	podeAndar = true;

	if (moveAle == 0)
	{
		paraEsquerda = false;
		atualizarPosicao();
		atualizaAnimacao();
	}
	else if (moveAle == 1)
	{
		paraEsquerda = true;
		atualizarPosicao();
		atualizaAnimacao();
	}
	else
	{
		podeAndar = false;
		atualizarPosicao();
		atualizaAnimacao();
	}


	float dt = relogio.getElapsedTime().asSeconds();
	if (dt >= 1.0f) {
		moveAle = rand() % 3;
		relogio.restart();
	}
}

void Inimigo::colisao(Entidade* entidadeColidida)
{
	if (entidadeColidida->getID() == Id::id::jogador) {
		atacando = true;
		tempoAtaque = relogio.getElapsedTime().asSeconds();
		printf("%f\n", tempoAtaque);
	}
	else if (entidadeColidida->getID() == Id::id::chao) {
		// Caso o Jogador esteja colidindo por cima, ou seja, caindo por cima pra plataforma
		if ((body.getPosition().y + body.getSize().y / 2) < entidadeColidida->getCorpo().getPosition().y) {
			body.setPosition(sf::Vector2f(body.getPosition().x, entidadeColidida->getCorpo().getPosition().y - body.getSize().y));
			noAr = false;
			velFinal.y = 0.0;
		}
	}
	else if (entidadeColidida->getID() == Id::id::plataforma) {
		// Caso o Jogador esteja colidindo por cima, ou seja, caindo por cima pra plataforma
		if ((body.getPosition().y + body.getSize().y / 2) < entidadeColidida->getCorpo().getPosition().y) {
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
			velFinal.y = 0.3f;
		}
	}
	else {
		printf("Colidiu player\n");
	}
}

void Inimigo::atualizar() {

	sf::Vector2f posJogador = jogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = getCorpo().getPosition();

	//verifica se ira seguir jogador ou ira se movimentar aleatoriamente
	if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y)
	{
		segueJogador(posInimigo, posJogador);
	}
	else {
		movimentoAle();
	}

	posAnt = body.getPosition();

}

void Inimigo::atualizaAnimacao() {
	if (atacando) {
		animacao.atualizar(paraEsquerda, "ATACA");
	}
	else if (noAr && velFinal.y > 0.0f) {
		animacao.atualizar(paraEsquerda, "CAI");
	}
	else if (noAr) {
		animacao.atualizar(paraEsquerda, "PULA");
	}
	else if (podeAndar) {
		animacao.atualizar(paraEsquerda, "CORRE");
	}
	else {
		animacao.atualizar(paraEsquerda, "PARADO");
	}
}