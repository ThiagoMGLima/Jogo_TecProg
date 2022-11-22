#include "Entidade.h"

Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const Id::id id) :
	tamanho(tam), body(sf::RectangleShape(tam)), posicao(pos), Ente(id)
{
	body.setPosition(pos);
}


Entidade::~Entidade()
{

}

const sf::RectangleShape Entidade::getCorpo()
{
	return body;
}

const sf::Vector2f Entidade::getPosicao()
{
	return posicao;
}

/*void Entidade::setPos(sf::Vector2f pos) {
	body.setPosition(pos);
	this->posicao = pos;
}*/

const sf::Vector2f Entidade::getPosAnt()
{
	return posAnt;
}

const sf::Vector2f Entidade::getTamanho()
{
	return tamanho;
}

void Entidade::mudarPosicao(sf::Vector2f posicao)
{
	body.setPosition(posicao);
	this->posicao = posicao;
}

void Entidade::desenha() {
	pGerenciadorGrafico->desenhaNaTela(body);
}