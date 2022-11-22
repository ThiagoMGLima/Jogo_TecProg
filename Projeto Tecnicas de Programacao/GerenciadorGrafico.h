#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#define TELA_X 1200.0f
#define TELA_Y 

namespace NomeJogo {
	namespace Gerenciador {

		/* Na cria��o do Gerenciador Gr�fico, ser� utilizado o Padr�o de projeto Singleton, para que assim seja instanciado
		apenas um Gerenciador Gr�fico para toda a execu��o do projeto. Para isso, a fun��o construtora da Classe ser� privada */
		class GerenciadorGrafico {
		private:

			sf::RenderWindow* window;

			//Camera
			sf::View camera;
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
			sf::Texture CarregarTextura(const char* caminhoTextura);
			void moveCamera(const sf::Vector2f posJogador);
			const sf::View getCamera();
		};
	}
}