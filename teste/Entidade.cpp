#include "Entidade.h"

Entidade::Entidade():body(sf::Vector2f(100.f,100.f)){
}

Entidade::~Entidade()
{

}

const sf::RectangleShape Entidade::getCorpo()
{
	return sf::RectangleShape();
}

