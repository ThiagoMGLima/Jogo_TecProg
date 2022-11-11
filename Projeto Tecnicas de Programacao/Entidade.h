#pragma once
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"

namespace NomeJogo {
	class Entidade {

	protected:
		sf::RectangleShape body;
		sf::RenderWindow* window;
		// Gerenciador Gráfico
		Gerenciador::GerenciadorGrafico* pGrafico;
	public:
		Entidade();
		~Entidade();

		void setWindow(sf::RenderWindow* window) {
			this->window = window;
		}
		void desenhaNaTela() {
			pGrafico->desenhaNaTela(window, body);
		}
	};
}