#pragma once
#include "Imagem.h"
#include <map>

class Animacao
{
private:
	sf::RectangleShape* corpo;
	std::map<std::string, Imagem*> mapImagem;
	sf::Clock relogio;
	std::string imgAtual;
public:
	Animacao(sf::RectangleShape* body);
	~Animacao();
	void atualizar(const bool paraEsquerda, std::string imgAtual);
	void addAnimacao(const char* caminhoTextura, std::string nomeanimacao, const unsigned int qtdImagem, const float Troca, const sf::Vector2f escala);
};
