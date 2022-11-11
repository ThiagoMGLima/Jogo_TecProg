#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"


namespace NomeJogo {
	namespace Gerenciador {
		/* Na cria��o do Gerenciador Gr�fico, ser� utilizado o Padr�o de projeto Singleton, para que assim seja instanciado
	apenas um Gerenciador Gr�fico para toda a execu��o do projeto. Para isso, a fun��o construtora da Classe ser� privada */
		class GerenciadorGrafico {
		private:
			static GerenciadorGrafico* pGerenciadorGrafico;
			// Fun��o construtora da classe
			GerenciadorGrafico();

		public:
			// Fun��o destrutora
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

