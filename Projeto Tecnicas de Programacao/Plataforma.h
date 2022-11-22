#include "Terreno.h"

class Plataforma :public Terreno
{
protected:
public:
	void atualizar();
	void colisao(Entidade* entidadeColidida);
	Plataforma(Id::id id, sf::Vector2f pos, sf::Vector2f tam, const char* caminhoTextura);
	~Plataforma();
};