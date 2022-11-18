#pragma once 

#include <SFML\Graphics.hpp>
#include "ListaEntidade.h"
#include <cmath>

namespace NomeJogo {

    namespace Gerenciador {

        class GerenciadorColisao {
        private:
            ListaEntidade* listaPersonagem;
        public:
            GerenciadorColisao(ListaEntidade* listaPersonagem);
            ~GerenciadorColisao();
            void verificaColisao(Entidade* ent1, Entidade* ent2);
            void executar();
        };

    }

}