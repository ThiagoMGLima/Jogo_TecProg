#include "SFML/Graphics.hpp"
#include "cmath"

namespace NomeJogo {
	namespace Gerenciador {
		class GerenciadorColisao {
		private:

		public:
			GerenciadorColisao();
			~GerenciadorColisao();
			const sf::Vector2f calculaColisao();
			void executar();
		};
	}
}
