#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "Entidade.hpp"
#include "Jogador.hpp"
namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo: public Entidade
        {
            protected:
                bool danoso;
            public:
                Obstaculo();
                ~Obstaculo();
                virtual void executar();
                virtual void obstacular(Jogador* p);
                virtual void salvar();
        };
    } using namespace Obstaculos;
} using namespace Entidades;

#endif
