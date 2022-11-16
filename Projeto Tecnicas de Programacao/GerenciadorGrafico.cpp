#include "GerenciadorGrafico.h"

NomeJogo::Gerenciador::GerenciadorGrafico* NomeJogo::Gerenciador::GerenciadorGrafico::pGerenciadorGrafico = nullptr;

NomeJogo::Gerenciador::GerenciadorGrafico::GerenciadorGrafico() :
	window(new sf::RenderWindow(sf::VideoMode(800.0f, 600.0f), "Jogo"))
{

}

NomeJogo::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico()
{
	if (window) {
		delete(window);
		window = nullptr;
	}
}


NomeJogo::Gerenciador::GerenciadorGrafico* NomeJogo::Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGerenciadorGrafico == nullptr) {

		pGerenciadorGrafico = new GerenciadorGrafico();
	}
	return pGerenciadorGrafico;
}

sf::RenderWindow* NomeJogo::Gerenciador::GerenciadorGrafico::getWindow()
{
	return window;
}

void NomeJogo::Gerenciador::GerenciadorGrafico::desenhaNaTela(sf::RectangleShape body) {
	window->draw(body);
}

void NomeJogo::Gerenciador::GerenciadorGrafico::LimparJanela()
{
	window->clear();
}

void NomeJogo::Gerenciador::GerenciadorGrafico::mostrarNaTela()
{
	window->display();
}

void NomeJogo::Gerenciador::GerenciadorGrafico::FechaJanela()
{
	window->close();
}

bool NomeJogo::Gerenciador::GerenciadorGrafico::verificaJanelaAberta()
{
	if (window->isOpen()) {
		return true;
	}
	else {
		return false;
	}
}