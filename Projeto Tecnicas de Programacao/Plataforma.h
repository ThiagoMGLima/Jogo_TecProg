#include "Entidade.h"

namespace NomeJogo {
	namespace Obstaculos {
		class Plataforma :public Entidade
		{
		private:
		public:
			Plataforma();
			Plataforma(const sf::RectangleShape body, sf::Vector2f pos, sf::Vector2f tam);
			~Plataforma();
			void colisao(Entidade* entidadeColidida);
		};
	}
}

