#include "Entidade.h"

Entidade::Entidade() :body(sf::Vector2f(100.f, 100.f)) {
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
	body.setPosition(posicao.x, posicao.y);
}
