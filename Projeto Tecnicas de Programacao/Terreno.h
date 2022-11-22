#pragma once
#include "Entidade.h"
class Terreno :
    public Entidade
{
protected:
    sf::Texture textura;
public:
    Terreno(const sf::Vector2f pos, const sf::Vector2f tam, const Id::id id);
    ~Terreno();
    virtual void atualizar() = 0;
};
