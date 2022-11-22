#pragma once
#include "Ente.h"
#include "layer.h"


namespace NomeJogo
{
    namespace Parallax
    {

        class Parallax :
            public Ente
        {
        private:
            sf::Vector2f Anterior;
            std::vector<Layer*> layers;
        public:
            Parallax(const Id::id id);
            ~Parallax();
            void draw();
            void addCamada(const char* caminhoTextura, const float vel);
            void executar();
        };
    }

}