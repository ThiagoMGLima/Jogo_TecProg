#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

namespace NomeJogo {
	namespace Gerenciador {
		
		/* Na cria��o do Gerenciador Gr�fico, ser� utilizado o Padr�o de projeto Singleton, para que assim seja instanciado
		apenas um Gerenciador Gr�fico para toda a execu��o do projeto. Para isso, a fun��o construtora da Classe ser� privada */
		class GerenciadorGrafico {
		private:
			
			sf::RenderWindow* window;
			static GerenciadorGrafico* pGerenciadorGrafico;
			
			// Fun��o construtora da classe em privado
			GerenciadorGrafico();			
	
		public:
			// Fun��o destrutora
			~GerenciadorGrafico();

			static GerenciadorGrafico* getGerenciadorGrafico();
			sf::RenderWindow* getWindow();
			void desenhaNaTela(sf::RectangleShape body);
			void LimparJanela();
			void mostrarNaTela();
			void FechaJanela();
			bool verificaJanelaAberta();
			};
		}
}


	
