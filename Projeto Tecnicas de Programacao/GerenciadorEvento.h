#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace NomeJogo {
	namespace Gerenciador {
		class GerenciadorEvento
		{
		private:
			// Ponteiro para o gerenciador gráfico
			GerenciadorGrafico* pGrafico;
			// Ponteiro para o jogador
			Jogador* pJogador;

			// Construtora privada para o padrão de projetos singleton
			static GerenciadorEvento* pEvento;
			GerenciadorEvento();
		public:
			~GerenciadorEvento(); // Destrutora
			static GerenciadorEvento* getGerenciadorEvento();
			void setJogador(Jogador* pJogador); // Configurando o personagem principal do jogo
			void verificaTeclaPressionada(sf::Keyboard::Key tecla);
			void verificaTeclaSolta(sf::Keyboard::Key tecla);
			void executar();
		};
	}
}
