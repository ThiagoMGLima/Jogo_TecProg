#include "Terreno.h"

class Espinhos :public Terreno
{
protected:
	bool intervaloDano;
public:
	void atualizar();
	void colisao(Entidade* entidadeColidida);
	bool getIntervaloDano();
	void setIntervaloDano(bool intervaloDano);
	Espinhos(Id::id id, sf::Vector2f pos, sf::Vector2f tam, const char* caminhoTextura);
	~Espinhos();
};