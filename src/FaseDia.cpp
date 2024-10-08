#include "FaseDia.hpp"
#include "ProjectileBot.hpp"
#include "Gumbot.hpp"
#include "Agua.hpp"
#include "Bandeira.hpp"
#include "ProjectileBot.hpp"
#include "ByteCrusher.hpp"
#include "Maquina_Projeteis.hpp"
#include "Plataforma.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Estados.hpp"
#include "Gerenciador_Eventos.hpp"
#include "Gerenciador_Inputs.hpp"

#include <cstdlib>
#include <ctime>

namespace Fases
{
    FaseDia::FaseDia(float comprimento)
        : Fase(FASE_DIA_PATH, comprimento),
          maxGumbots(6),
          maxProjectileBots(6),
          maxMaquinaProjeteis(5),
          maxAgua(6),
          minAgua(3),
          minProjectileBots(3),
          minMaquinaProjeteis(3),
          minGumbots(3)
    {
        criarEntidades();
    }

    FaseDia::~FaseDia()
    {}

    void FaseDia::criarGumbots()
    {
        int nGumbots = 0;

        for(int i = 0; i < altura && nGumbots < maxGumbots; ++i)
            for(int j = 0; j < largura && nGumbots < maxGumbots; ++j)
                if(getTile(j, i) == 4)
                    if(nGumbots < minGumbots || ((rand()%5) > 1))
                    {
                        Gumbot* pgumbot = new Gumbot(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirInimigos(pgumbot);
                        entidades.inserirNoFim(static_cast<Entidade*>(pgumbot));
                        ++nGumbots;
                    }
    }
    
    void FaseDia::criarProjectileBots()
    {
        int nProjectileBots = 0;

        for(int i = 0; i < altura && nProjectileBots < maxProjectileBots; ++i)
            for(int j = 0; j < largura && nProjectileBots < maxProjectileBots; ++j)
                if(getTile(j, i) == 3)
                    if(nProjectileBots < minProjectileBots || ((rand()%5) > 1))
                    {
                        ProjectileBot* pprojectilebot = new ProjectileBot(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirInimigos(pprojectilebot);
                        entidades.inserirNoFim(static_cast<Entidade*>(pprojectilebot));
                        ++nProjectileBots;
                    }
    }

    void FaseDia::criarMaquinaProjeteis()
    {
        int nMaquinaProjeteis = 0;

        for(int i = 0; i < altura && nMaquinaProjeteis < maxMaquinaProjeteis; ++i)
            for(int j = 0; j < largura && nMaquinaProjeteis < maxMaquinaProjeteis; ++j)
                if(getTile(j, i) == 5)
                    if(nMaquinaProjeteis < minMaquinaProjeteis || ((rand()%5) > 1))
                    {
                        Maquina_Projeteis* pmaquinaprojeteis = new Maquina_Projeteis(sf::Vector2f(j*comprimentoTile, i*comprimentoTile+6));
                        entidades.inserirNoInicio(static_cast<Entidade*>(pmaquinaprojeteis));
                        ++nMaquinaProjeteis;
                    }
    }

    void FaseDia::criarAgua()
    {
        int nAgua = 0;

        for(int i = 0; i < altura && nAgua < maxAgua; ++i)
            for(int j = 0; j < largura && nAgua < maxAgua; ++j)
                if(getTile(j, i) == 2)
                    if(nAgua < minAgua || ((rand()%5) > 1))
                    {
                        Agua* agua = new Agua(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirObstaculos(agua);
                        entidades.inserirNoFim(static_cast<Entidade*>(agua));
                        ++nAgua;
                    }
    }

    void FaseDia::criarPilares()
    {
        for(int i = 0; i < altura; ++i)
            for(int j = 0; j < largura; ++j)
                if(getTile(j, i) == 7)
                {    
                    Plataforma* plat = new Plataforma(sf::Vector2f(j*comprimentoTile, i*comprimentoTile), sf::Vector2f(16.0f, 16.0f), false);
                    entidades.inserirNoInicio(static_cast<Entidade*>(plat));
                }
    }

    void FaseDia::criarEntidades()
    {
        if(!tiles)
            return;

        srand(time(NULL));

        criarPlataformas();
        criarPilares();
        criarMaquinaProjeteis();
        criarAgua();
        criarGumbots();
        criarProjectileBots();

        entidades.inserirNoFim(new Bandeira(sf::Vector2f(1*16.0f, 6*16.0f), this, pjogadorum, pjogadordois));
    }
}