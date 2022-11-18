#pragma once
#include "Entidade.h"
class Terreno :
    public Entidade
{
public:
protected:
    Terreno();
    ~Terreno();
    virtual void atualizar() = 0;
};

