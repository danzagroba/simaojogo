#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>


Gerenciador_Grafico* Gerenciador_Grafico::pgergraf = NULL;

Gerenciador_Grafico::Gerenciador_Grafico():
largura(800),
altura(600),
maxX(200),
maxY(150),
limitefps(60),
window(NULL),
camera(),
deltaTime(0.0f),
clock(),
posInicial(),
fundodia(true)
{}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
    if(window)
    {
        delete window;
    }
    if(pgergraf)
    {
        delete pgergraf;
    }
    pgergraf = NULL;
}

const float Gerenciador_Grafico::lerp(const float a, const float b, const float t) const
{
    return a + t*(b - a);
}

Gerenciador_Grafico* Gerenciador_Grafico::getGerenciador_Grafico()
{
    if(pgergraf == NULL)
    {
        pgergraf = new Gerenciador_Grafico();
        if(pgergraf == NULL)
        {
            exit(1);
        }
    }
    return pgergraf;
}
sf::RenderWindow* Gerenciador_Grafico::getJanela()
{
    if(pgergraf)
    {
        return this->window;
    }
    return NULL;
}
void Gerenciador_Grafico::desenharEnte(Ente* pE)
{
    if(window && pE)
    {
        window->draw(pE->getFigura());
    }
}
void Gerenciador_Grafico::desenhar(const sf::Drawable& desenho)
{
    if(window)
        window->draw(desenho);
}
void Gerenciador_Grafico::desenhartxt(sf::Text* txt)
{
    if(window)
        window->draw(*txt);
}
bool Gerenciador_Grafico::getisOpen(){ return window->isOpen(); }
void Gerenciador_Grafico::setTamanhoJanela(int lar, int alt)
{
    largura = lar;
    altura = alt;
    camera.setSize(lar/4, alt/4);
}
void Gerenciador_Grafico::setMaximosCamera(float x, float y)
{
    maxX = x;
    maxY = y;
}
void Gerenciador_Grafico::setLimiteFPS(int lfps)
{
    limitefps = lfps;
}
void Gerenciador_Grafico::setfundo(const bool fundod)
{
    fundodia = fundod;
}
void Gerenciador_Grafico::clear()
{
    if(window)
    {
        if(fundodia)
        {
            window->clear(sf::Color(95, 205, 228));
        } else
        {
            window->clear(sf::Color(4, 0, 48));
        }
    }
}
void Gerenciador_Grafico::display()
{
    if(window)
    {
        window->display();
    }
}
void Gerenciador_Grafico::configurar()
{
    if(window)
    {
        delete window;
    }
    window = new sf::RenderWindow(sf::VideoMode(largura, altura), "ROBOT++", sf::Style::Titlebar | sf::Style::Close);
    if(!window)
    {
        exit(1);
    }
    window->setFramerateLimit(limitefps);
    posInicial = window->getView();
}

void Gerenciador_Grafico::fecharjanela()
{
    window->close();
}

void Gerenciador_Grafico::processarEvento()
{
    if(!window)
        return;
    sf::Event event;
    while(window->pollEvent(event))
        if(event.type == sf::Event::Closed)
            window->close();
}

void Gerenciador_Grafico::setCamera(const sf::Vector2f& centro)
{
    sf::Vector2f novoCentro = sf::Vector2f( lerp(camera.getCenter().x, centro.x, 0.1f), 
                                            lerp(camera.getCenter().y, centro.y, 0.1f) );

    if(novoCentro.x < (float)largura/8.0f)
        novoCentro.x = (float)largura/8.0f;
    else if(novoCentro.x > maxX - (float)largura/8.0f)
        novoCentro.x = maxX - (float)largura/8.0f;

    if(novoCentro.y < (float)altura/8.0f)
        novoCentro.y = (float)altura/8.0f;
    else if(novoCentro.y > maxY - (float)altura/8.0f)
        novoCentro.y = maxY - (float)altura/8.0f;

    camera.setCenter(novoCentro);
    window->setView(camera);
}

void Gerenciador_Grafico::setCameraSize(const float width, const float height)
{
    camera.setSize(width, height);
}

void Gerenciador_Grafico::atualizarDeltaTime()
{
    deltaTime = clock.restart().asMilliseconds();
}

const float Gerenciador_Grafico::getDeltaTime() const
{
    return deltaTime;
}

const sf::View& Gerenciador_Grafico::getCamera() const
{
    return camera;
}

void Gerenciador_Grafico::resetCamera()
{
    posInicial.setCenter(400.0f, 300.0f);
    window->setView(posInicial);
}