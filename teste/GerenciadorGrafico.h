#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

namespace NomeJogo {
	namespace Gerenciador {
		
		/* Na criação do Gerenciador Gráfico, será utilizado o Padrão de projeto Singleton, para que assim seja instanciado
		apenas um Gerenciador Gráfico para toda a execução do projeto. Para isso, a função construtora da Classe será privada */
		class GerenciadorGrafico {
		private:
			
			sf::RenderWindow* window;
			static GerenciadorGrafico* pGerenciadorGrafico;
			
			// Função construtora da classe em privado
			GerenciadorGrafico();			
	
		public:
			// Função destrutora
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


	
