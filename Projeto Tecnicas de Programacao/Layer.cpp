#include "Layer.h"

void Layer::mudarTextura()
{
	sf::RectangleShape auxLayer; //variavel temporaria
	auxLayer = fundo;
	fundo = fundo2;
	fundo2 = auxLayer;

}

Layer::Layer(const sf::Vector2f jTamanho, sf::Texture textura, const float vel) :
	jTamanho(jTamanho), textura(textura), dimensao(0, 0, 0, 0), vel(vel)
{
	dimensao.width = -abs((const float)textura.getSize().x);
	dimensao.left = textura.getSize().x;
	dimensao.height = textura.getSize().y;

	fundo.setSize(jTamanho);
	fundo.setTexture(&this->textura);
	fundo.setPosition(0.0f, 0.0f);

	fundo2.setSize(jTamanho);
	fundo2.setTexture(&this->textura);
	fundo2.setPosition(jTamanho.x, 0.0f);
}

Layer::~Layer()
{
}

void Layer::drawLayer(sf::RenderWindow* window)
{
	window->draw(fundo);
	//se a camada tiver movimento
	if (vel != 0.0f) {
		window->draw(fundo2);
	}
}

void Layer::atualizar(const sf::Vector2f ds, const sf::Vector2f posCamera)
{
	const float Direita = posCamera.x + jTamanho.x / 2.0f;
	const float Esquerda = posCamera.x + jTamanho.y / 2.0f;

	//se a camada tiver movimento
	if (vel != 0.0f)
	{
		const sf::Vector2f posFundo = fundo.getPosition();
		const sf::Vector2f posFundo2 = fundo2.getPosition();

		//movimento das camadas contrario ao jogador  (se o jogador for pra direita ela vai pra esquerda)
		fundo.move(ds.x * -vel, 0.0f);
		fundo2.move(ds.x * -vel, 0.0f);

		if (ds.x > 0.0f) { //movimento do jogador para direita
			if (posFundo.x + jTamanho.x < Esquerda) {
				mudarTextura();
				fundo.setPosition(Esquerda, 0.0f);
				fundo2.setPosition(Direita, 0.0f);
			}
		}
		else { //movimento do jogador para a esquerda
			if (posFundo.x > Esquerda) {
				mudarTextura();
				fundo.setPosition(Esquerda - jTamanho.x, 0.0f);
				fundo2.setPosition(Esquerda, 0.0f);
			}
		}
	}
	else {
		fundo.setPosition(Esquerda, 0.0f);
	}
}
