#include "Terreno.h"

class Chao :public Terreno {
private:
public:
	Chao();
	Chao(string ID, sf::Vector2f tam, sf::Vector2f pos);
	~Chao();
	void colisao(Entidade* entidadeColidida);
	void atualizar();
};

