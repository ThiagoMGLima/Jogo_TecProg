#include "Terreno.h"

class Chao :public Terreno {
private:
public:
	Chao(sf::Vector2f tam, sf::Vector2f pos, const char* caminhoTextura);
	~Chao();
	void colisao(Entidade* entidadeColidida);
	void atualizar();
};