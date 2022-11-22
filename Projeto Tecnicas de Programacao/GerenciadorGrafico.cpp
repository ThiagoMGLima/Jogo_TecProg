#include "GerenciadorGrafico.h"
using namespace std;

NomeJogo::Gerenciador::GerenciadorGrafico* NomeJogo::Gerenciador::GerenciadorGrafico::pGerenciadorGrafico = nullptr;

NomeJogo::Gerenciador::GerenciadorGrafico::GerenciadorGrafico() :
	window(new sf::RenderWindow(sf::VideoMode(1200.0f, 700.0f), "Jogo")),
	camera(sf::Vector2f(1200.0f / 2.0f, 700 / 2.0f), sf::Vector2f(1200.0f, 700.0f))
{
	if (window == nullptr) {
		std::cout << "ERROR::NomeJogo::Gerenciador::GerenciadorGrafico nao foi possivel criar uma janela grafica" << std::endl;
		exit(1);
	}
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
	// *Aplicacao de padrao de projeto Singleton

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

sf::Texture NomeJogo::Gerenciador::GerenciadorGrafico::CarregarTextura(const char* caminhoTextura) {
	sf::Texture textura;

	//carrega a textura ja verificando se carregou corretamente
	if (!textura.loadFromFile(caminhoTextura)) {
		std::cout << "ERRO::NomeJogo::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da textura - " << caminhoTextura << std::endl;
		exit(1);
	}
	return textura;
}

//Fazer camera que segue jogador(atualizar camera, getCamera)

void NomeJogo::Gerenciador::GerenciadorGrafico::moveCamera(const sf::Vector2f posJogador) {
	camera.setCenter(posJogador.x, 350.0f);
	window->setView(camera);
}

const sf::View NomeJogo::Gerenciador::GerenciadorGrafico::getCamera() {
	return camera;
}