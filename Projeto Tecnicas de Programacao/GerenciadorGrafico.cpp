#include "GerenciadorGrafico.h"

NomeJogo::Gerenciador::GerenciadorGrafico::GerenciadorGrafico()
{
}

NomeJogo::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico()
{
}


void NomeJogo::Gerenciador::GerenciadorGrafico::setWindow(sf::RenderWindow* window, sf::RenderWindow* janela) {
	window = janela;
}

void NomeJogo::Gerenciador::GerenciadorGrafico::desenhaNaTela(sf::RenderWindow* window, sf::RectangleShape body) {
	window->draw(body);
}

void NomeJogo::Gerenciador::GerenciadorGrafico::LimparJanela(sf::RenderWindow* window)
{
	window->clear();
}

void NomeJogo::Gerenciador::GerenciadorGrafico::mostrarNaTela(sf::RenderWindow* window)
{
	window->display();
}

void NomeJogo::Gerenciador::GerenciadorGrafico::FechaJanela(sf::RenderWindow* window)
{
	window->close();
}

bool NomeJogo::Gerenciador::GerenciadorGrafico::verificaJanelaAberta(sf::RenderWindow* window)
{
	if (window->isOpen()) {
		return true;
	}
	else {
		return false;
	}
}
