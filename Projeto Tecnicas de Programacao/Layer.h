#pragma once
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <stdio.h>

class Layer
{
private:
	sf::Texture textura;
	sf::RectangleShape fundo;
	sf::RectangleShape fundo2;
	const sf::Vector2f jTamanho;
	sf::IntRect dimensao;
	const float vel;

	void mudarTextura();
public:
	Layer(const sf::Vector2f jTamanho, sf::Texture textura, const float vel);
	~Layer();
	void drawLayer(sf::RenderWindow* window);
	void atualizar(const sf::Vector2f ds, const sf::Vector2f posCamera);
};

