#pragma once

#include "Obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Agua: public Obstaculo
        {
            private:
                static int dano;

            public:
                Agua(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
                ~Agua();
                
                void executar();
                void obstacular();
                void salvar();

                static const int getDano();
        };
    } using namespace Obstaculos;
} using namespace Entidades;