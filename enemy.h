#include <SFML/Graphics.hpp>
#include <string.h>
#include "bomb.h"
using namespace sf;
class enemies
{
public:
    virtual void attack(sf::RenderWindow &window, bomb*& bx) = 0;
    virtual float getpositionx() = 0;
    virtual float getpositiony() = 0;
    virtual Sprite get() = 0;
    virtual void draw(RenderWindow &window) = 0;
    virtual ~enemies(){};
};
class Invader : public enemies
{
    public:
    float posx;
    float posy;
    Sprite enm;
    void attack(sf::RenderWindow &window, bomb*& bx) override {}
    float getpositionx() override {return posx;}
    float getpositiony() override {return posy;}
    Sprite get() override {return enm;}
    void draw(RenderWindow &window) override {}
    
};
class Alpha : public Invader
{
public:
    Sprite alpha;
    Texture tex;
    Clock clock;
    float timer;

    Alpha()
    {
        tex.loadFromFile("img/enemy_1.png");
        alpha.setTexture(tex);
        alpha.setScale(0.8, 0.8);
    }

    Alpha(int x, int y)
    {
        tex.loadFromFile("img/enemy_1.png");
        alpha.setTexture(tex);
        alpha.setScale(0.8, 0.8);
        alpha.setPosition(x, y);
    }

    Sprite get()
    {
        enm = alpha;
        return enm;
    }
    float getpositionx()
    {
        posx = alpha.getPosition().x;
        return posx;
    }
    float getpositiony()
    {
        float posy = alpha.getPosition().y;
        return posy;
    }
    void attack(sf::RenderWindow &window, bomb*& bx)
    {
        // if (clock.getElapsedTime().asSeconds() < 0.03) 
        // {                                 
        //     window.draw(bx->bob);                                                                           
        // }
        // if (clock.getElapsedTime().asSeconds() > 0.03)
        // {
        //     bx->bob.setPosition(bx->bob.getPosition().x  , bx->bob.getPosition().y + 10);
        //     timer+= clock.getElapsedTime().asSeconds();
        //     clock.restart();
        // }
        if (bx->bob.getPosition().y > 1500)
        {
           bx->bob.setPosition(alpha.getPosition().x + 30  , alpha.getPosition().y + 50);
        }
        
    }
    
    void draw(sf::RenderWindow &window)
    {
        window.draw(alpha);
        //window.draw(bx->bob);
    }
};

class Beta : public Invader
{
public:
    Sprite beta;
    Texture tex;
    Clock clock;

    Beta()
    {
        tex.loadFromFile("img/enemy_2.png");
        beta.setTexture(tex);
        beta.setScale(0.7, 0.7);
    }

    Beta(int x, int y)
    {
        tex.loadFromFile("img/enemy_2.png");
        beta.setTexture(tex);
        beta.setScale(0.7, 0.7);
        beta.setPosition(x, y);
    }
    Sprite get()
    {
        enm = beta;
        return enm;
    }
    float getpositionx()
    {
        posx = beta.getPosition().x;
        return posx;
    }
    float getpositiony()
    {
        float posy = beta.getPosition().y;
        return posy;
    }
    void attack(sf::RenderWindow &window, bomb*& bx)
    {
        // if (clock.getElapsedTime().asSeconds() < 0.03) 
        // {                                 
        //     window.draw(bx->bob);                                                                           
        // }
        // if (clock.getElapsedTime().asSeconds() > 0.03)
        // {
        //     bx->bob.setPosition(bx->bob.getPosition().x  , bx->bob.getPosition().y + 10);
        //     clock.restart();
        // }
        if (bx->bob.getPosition().y > 2000)
        {
           bx->bob.setPosition(beta.getPosition().x + 30  , beta.getPosition().y + 50);
        }
    }
    void draw(sf::RenderWindow &window)
    {
        window.draw(beta);
    }
};

class Gamma : public Invader
{
public:
    Sprite gamma;
    Texture tex;
    Clock clock;
    float timer;

    Gamma()
    {
        tex.loadFromFile("img/enemy_3.png");
        gamma.setTexture(tex);
        gamma.setScale(0.8, 0.8);
    }

    Gamma(int x, int y)
    {
        tex.loadFromFile("img/enemy_3.png");
        gamma.setTexture(tex);
        gamma.setScale(0.5, 0.5);
        gamma.setPosition(x, y);
    }

    Sprite get()
    {
        enm = gamma;
        return enm;
    }
    float getpositionx()
    {
        posx = gamma.getPosition().x;
        return posx;
    }
    float getpositiony()
    {
        float posy = gamma.getPosition().y;
        return posy;
    }
    void attack(sf::RenderWindow &window, bomb*& bx)
    {
        // if (clock.getElapsedTime().asSeconds() < 0.03) 
        // {                                 
        //     window.draw(bx->bob);                                                                           
        // }
        // if (clock.getElapsedTime().asSeconds() > 0.03)
        // {
        //     bx->bob.setPosition(bx->bob.getPosition().x  , bx->bob.getPosition().y + 10);
        //     timer+= clock.getElapsedTime().asSeconds();
        //     clock.restart();
        // }
        if (bx->bob.getPosition().y > 1000)
        {
           bx->bob.setPosition(gamma.getPosition().x + 30  , gamma.getPosition().y + 50);
        }
        
    }
    
    void draw(sf::RenderWindow &window)
    {
        window.draw(gamma);
    }
};
