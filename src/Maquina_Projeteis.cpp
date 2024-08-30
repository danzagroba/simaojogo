#include "Maquina_Projeteis.hpp"

Maquina_Projeteis::Maquina_Projeteis(const sf::Vector2f& pos):
Obstaculo()
{
    timer.restart();
    setFigura(SPRITE_PATHMAQUINAPROJETEIS);
    setPos(pos.x, pos.y);
}
Maquina_Projeteis::~Maquina_Projeteis()
{

}
void Maquina_Projeteis::criartiromaquina()
{
    if(timer.getElapsedTime().asSeconds()>2.5)
    {
        Projetil* pprojetil = new Projetil(this, 1, sf::Vector2f(-0.1f, -0.1f), 40);
        if(pprojetil)
        {   
            projeteismaquina.push_back(pprojetil);
        }
        timer.restart();
    }
}

void Maquina_Projeteis::removertiromaquina(Projetil* ep)
{
    list<Projetil*>::iterator it = std::find(projeteismaquina.begin(), projeteismaquina.end(), ep);
    if (it != projeteismaquina.end()) {
        projeteismaquina.erase(it);
    }
}

std::list<Projetil*>* Maquina_Projeteis::getprojeteismaquina()
{
    return &projeteismaquina;
}


void Maquina_Projeteis::executar()
{

}
void Maquina_Projeteis::salvar()
{

}
void Maquina_Projeteis::obstacular(Jogador* pJogador)
{

}