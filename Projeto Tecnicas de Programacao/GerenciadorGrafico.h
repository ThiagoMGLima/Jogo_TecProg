#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"


namespace NomeJogo {
	namespace Gerenciador {
		/* Na criação do Gerenciador Gráfico, será utilizado o Padrão de projeto Singleton, para que assim seja instanciado
	apenas um Gerenciador Gráfico para toda a execução do projeto. Para isso, a função construtora da Classe será privada */
		class GerenciadorGrafico {
		private:
			static GerenciadorGrafico* pGerenciadorGrafico;
			// Função construtora da classe
			GerenciadorGrafico();

		public:
			// Função destrutora
			~GerenciadorGrafico();
			void setWindow(sf::RenderWindow* window, sf::RenderWindow* janela);
			void desenhaNaTela(sf::RenderWindow* window, sf::RectangleShape body);
			void LimparJanela(sf::RenderWindow* window);
			void mostrarNaTela(sf::RenderWindow* window);
			void FechaJanela(sf::RenderWindow* window);
			bool verificaJanelaAberta(sf::RenderWindow* window);

		};
	}
}

