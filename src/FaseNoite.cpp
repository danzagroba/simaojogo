#include "FaseNoite.hpp"
#include "ProjectileBot.hpp"

namespace Fases
{
    FaseNoite::FaseNoite(Gerenciadores::Gerenciador_Grafico* pGG,
                         Gerenciadores::Gerenciador_Colisoes* pCO,
                         Entidades::Personagens::Jogador* jgdr,
                         Entidades::Personagens::Jogador* jgdrdois,
                         float comprimento)
        : Fase(FASE_NOITE_PATH, pGG, pCO, jgdr, jgdrdois, comprimento)
    {}

    FaseNoite::~FaseNoite()
    {}

    void FaseNoite::criarEntidades()
    {
        if(!tiles)
            return;
        
        criarPlataformas();

        Gumbot* pgumbot = new Gumbot(sf::Vector2f(25.0f, 25.0f));
        gerColisoes->inserirInimigos(pgumbot);
        entidades.inserirNoFim(static_cast<Entidade*>(pgumbot));

        //ProjectileBot* pprojectilebot = new ProjectileBot(sf::Vector2f(4.0f*comprimentoTile, 25.0f));
        

        std::cout<<"gumbot criado"<<endl;
    }
}