#include <string>
#include "GerenciadorGrafico.h"

using std::string;

class Ente
{
protected:
	// ID para identificar o Ente
	string ID;
	// Gerenciador Grafico
	NomeJogo::Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;

public:
	Ente();
	Ente(string ID);
	~Ente();
	virtual void atualizar() = 0;
	void setID(string ID);
	const string getID();
};
