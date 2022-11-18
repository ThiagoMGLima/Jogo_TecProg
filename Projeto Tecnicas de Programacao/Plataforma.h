#include "Terreno.h"

class Plataforma :public Terreno
{
protected:

public:
	void atualizar();
	void colisao(Entidade* entidadeColidida);
	Plataforma();
	Plataforma(string ID, sf::Vector2f pos, sf::Vector2f tam);
	~Plataforma();
};
