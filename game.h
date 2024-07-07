
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "enemy.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
    Sprite background;
    Texture bg_texture;
    Sprite resume;
    Texture r;
    Sprite help;
    Texture h;
    Player *p;
    enemies *aa[8];
    enemies *bb[6];
    enemies *gg[4];
    bullet *furry = new bullet;
    bomb *bxa[8];
    bomb *bxb[6];
    bomb *bxg[4];
    bomb *bxt[1];
    int level = 1;

    Game()
    {
        p = new Player("img/player_ship.png");
        bg_texture.loadFromFile("img/aaaaaa.jpg");
        r.loadFromFile("img/1920x1080-black-solid-color-backgroundaa.jpg");
        h.loadFromFile("img/17498.jpg");
        help.setTexture(h);
        resume.setTexture(r);
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);
    }

    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(780, 780), title);
        Clock clock;
        float timer = 0;
        float bt = 0;
        srand(0);
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            // clock.restart();
            timer += time;
            bt += time;
            bool yes = 0;
            int bull_spa = 0.5;
            static bool ak = 0;
            bool x = 0;
            static bool flag = 0;

            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
            }

            // movement
            static bool move = 0;
            if (move == 0)
            {
                if (Keyboard::isKeyPressed(Keyboard::Left))
                    p->move("l");
                if (Keyboard::isKeyPressed(Keyboard::Right))
                    p->move("r");
                if (Keyboard::isKeyPressed(Keyboard::Up))
                    p->move("u");
                if (Keyboard::isKeyPressed(Keyboard::Down))
                    p->move("d");
            }
            p->wrap_arnd();

            window.clear(Color::Black);
            window.draw(background);

            // power up fire
            if (e.key.code == Keyboard::O)
                ak = 1;
            if (ak == 1)
            {
                if (Keyboard::isKeyPressed(Keyboard::Space))
                {
                    p->fire_ak(yes, bull_spa = 2, furry);
                    x = 1;
                }
                if (x == 0)
                {
                    furry->move_y = p->sprite.getPosition().y - 50;
                    furry->move_x = p->sprite.getPosition().x + 32;
                    furry->bull.setPosition(furry->move_x, furry->move_y - 2000);
                }
            }

            // simple fire
            if (e.key.code == Keyboard::P)
                ak = 0;
            if (ak == 0)
            {
                bool bulletFired = false;
                if (e.key.code == Keyboard::Space && !bulletFired)
                {
                    p->fire_ak(yes, bull_spa = 2, furry);
                    bulletFired = true;
                }

                if (!bulletFired)
                {
                    furry->move_y = p->sprite.getPosition().y - 50;
                    furry->move_x = p->sprite.getPosition().x + 32;
                    furry->bull.setPosition(furry->move_x, furry->move_y - 2000);
                }
            }

                window.draw(p->sprite);
                window.draw(furry->bull);

                static bool bb_flag = 0;
                // calling constructors of bomb
                if (bb_flag == 0)
                {
                    for (int i = 0; i < 8; i++)
                    {
                        bxa[i] = new bomb("img/PNG/Lasers/laserGreen01.png");
                    }
                    for (int i = 0; i < 6; i++)
                    {
                        bxb[i] = new bomb("img/PNG/Lasers/laserBlue09.png");
                    }
                    for (int i = 0; i < 4; i++)
                    {
                        bxg[i] = new bomb("img/PNG/Lasers/laserRed11.png");
                    }
                }
                bb_flag = 1;

                // formation 1
                static bool formation = 0;
                if (level == 1)
                {
                    if (formation == 0)
                    {
                        aa[0] = new Alpha(200, 50);
                        aa[1] = new Alpha(200, 150);
                        aa[2] = new Alpha(200, 250);
                        aa[3] = new Alpha(300, 250);
                        aa[4] = new Alpha(400, 250);
                        aa[5] = new Alpha(500, 250);
                        aa[6] = new Alpha(500, 150);
                        aa[7] = new Alpha(500, 50);
                        bb[0] = new Beta(100, 250);
                        bb[1] = new Beta(100, 150);
                        bb[2] = new Beta(100, 50);
                        bb[3] = new Beta(600, 250);
                        bb[4] = new Beta(600, 150);
                        bb[5] = new Beta(600, 50);
                        gg[0] = new Gamma(0, 50);
                        gg[1] = new Gamma(0, 250);
                        gg[2] = new Gamma(690, 50);
                        gg[3] = new Gamma(690, 250);
                    }
                    formation = 1;
                }
                // formation 2
                if (level == 2)
                {
                    if (formation == 0)
                    {
                        aa[0] = new Alpha(350, 150);
                        aa[1] = new Alpha(300, 100);
                        aa[2] = new Alpha(250, 50);
                        aa[3] = new Alpha(400, 200);
                        aa[4] = new Alpha(400, 100);
                        aa[5] = new Alpha(450, 50);
                        aa[6] = new Alpha(300, 200);
                        aa[7] = new Alpha(350, 250);
                        bb[0] = new Beta(200, 150);
                        bb[1] = new Beta(500, 150);
                        bb[2] = new Beta(500, 300);
                        bb[3] = new Beta(200, 300);
                        bb[4] = new Beta(640, 150);
                        bb[5] = new Beta(60, 150);
                        gg[0] = new Gamma(0, 50);
                        gg[1] = new Gamma(0, 250);
                        gg[2] = new Gamma(690, 50);
                        gg[3] = new Gamma(690, 250);
                    }
                    formation = 1;
                }
                // formation 3
                if (level == 3)
                {
                    if (formation == 0)
                    {
                        aa[0] = new Alpha(350, 250);
                        // aa[1] = new Alpha(300, 100);
                        // aa[2] = new Alpha(250, 50);
                        // aa[3] = new Alpha(400, 200);
                        // aa[4] = new Alpha(400, 100);
                        // aa[5] = new Alpha(450, 50);
                        // aa[6] = new Alpha(300, 200);
                        // aa[7] = new Alpha(350, 250);
                        //  bb[0] = new Beta(200, 150);
                        //  bb[1] = new Beta(500, 150);
                        //  bb[2] = new Beta(500, 300);
                        //  bb[3] = new Beta(200, 300);
                        //  bb[4] = new Beta(640, 150);
                        //  bb[5] = new Beta(60, 150);
                        //  gg[0] = new Gamma(0, 50);
                        //  gg[1] = new Gamma(0, 250);
                        //  gg[2] = new Gamma(690, 50);
                        //  gg[3] = new Gamma(690, 250);
                    }
                    formation = 1;
                }

                // player death with alpha
                for (int i = 0; i < 8; i++)
                    if (aa[i] != nullptr && aa[i]->get().getPosition().x - 10 < int(p->sprite.getPosition().x) && aa[i]->get().getPosition().x + 50 > int(p->sprite.getPosition().x) && aa[i]->get().getPosition().y + 80 > int(p->sprite.getPosition().y) && aa[i]->get().getPosition().y - 30 < int(p->sprite.getPosition().y))
                    {
                        p->sprite.setPosition(-100, -100);
                        move = 1;
                    }

                // player death with alpha bullet
                for (int i = 0; i < 8; i++)
                    if (bxa[i] != nullptr)
                        if (bxa[i]->bob.getPosition().y > int(p->sprite.getPosition().y) && bxa[i]->bob.getPosition().y < int(p->sprite.getPosition().y) + 30 && p->sprite.getPosition().x < bxa[i]->bob.getPosition().x && p->sprite.getPosition().x > bxa[i]->bob.getPosition().x - 60)
                        {
                            p->sprite.setPosition(-100, -100);
                            move = 1;
                        }

                // player death with beta
                for (int i = 0; i < 6; i++)
                    if (bb[i] != nullptr && bb[i]->get().getPosition().x - 10 < int(p->sprite.getPosition().x) && bb[i]->get().getPosition().x + 50 > int(p->sprite.getPosition().x) && bb[i]->get().getPosition().y + 80 > int(p->sprite.getPosition().y) && bb[i]->get().getPosition().y - 30 < int(p->sprite.getPosition().y))
                    {
                        p->sprite.setPosition(-100, -100);
                        move = 1;
                    }

                // player death with beta bullet
                for (int i = 0; i < 6; i++)
                    if (bxb[i] != nullptr)
                        if (bxb[i]->bob.getPosition().y > int(p->sprite.getPosition().y) && bxb[i]->bob.getPosition().y < int(p->sprite.getPosition().y) + 30 && p->sprite.getPosition().x < bxb[i]->bob.getPosition().x && p->sprite.getPosition().x > bxb[i]->bob.getPosition().x - 60)
                        {
                            p->sprite.setPosition(-100, -100);
                            move = 1;
                        }

                // player death with gamma
                for (int i = 0; i < 4; i++)
                    if (gg[i] != nullptr && gg[i]->get().getPosition().x - 10 < int(p->sprite.getPosition().x) && gg[i]->get().getPosition().x + 50 > int(p->sprite.getPosition().x) && gg[i]->get().getPosition().y + 80 > int(p->sprite.getPosition().y) && gg[i]->get().getPosition().y - 30 < int(p->sprite.getPosition().y))
                    {
                        p->sprite.setPosition(-100, -100);
                        move = 1;
                    }

                // player death with gamma bullet
                for (int i = 0; i < 4; i++)
                    if (gg[i] != nullptr)
                        if (bxg[i]->bob.getPosition().y > int(p->sprite.getPosition().y) && bxg[i]->bob.getPosition().y < int(p->sprite.getPosition().y) + 30 && p->sprite.getPosition().x < bxg[i]->bob.getPosition().x && p->sprite.getPosition().x > bxg[i]->bob.getPosition().x - 60)
                        {
                            p->sprite.setPosition(-100, -100);
                            move = 1;
                        }

                // respawn
                if (e.key.code == Keyboard::E)
                {
                    p->sprite.setPosition(25, 600);
                    move = 0;
                }

                // alpha dmg
                static int death = 0;
                for (int i = 0; i < 8; i++)
                {
                    if (aa[i] != nullptr && furry->bull.getPosition().x < aa[i]->get().getPosition().x + 100 && furry->bull.getPosition().x > aa[i]->get().getPosition().x - 50 && furry->bull.getPosition().y < aa[i]->get().getPosition().y && furry->bull.getPosition().y > aa[i]->get().getPosition().y - 100)
                    {
                        death = i;
                        delete aa[i];
                        aa[i] = nullptr;
                        bxa[i]->death = 1;
                        flag = 1;

                        furry->bull.setPosition(-100, -100);
                    }
                }

                // beta dmg
                for (int i = 0; i < 6; i++)
                {
                    if (bb[i] != nullptr && furry->bull.getPosition().x < bb[i]->get().getPosition().x + 100 && furry->bull.getPosition().x > bb[i]->get().getPosition().x - 50 && furry->bull.getPosition().y < bb[i]->get().getPosition().y && furry->bull.getPosition().y > bb[i]->get().getPosition().y - 100)
                    {
                        death = 1;
                        delete bb[i];
                        bb[i] = nullptr;
                        bxb[i]->death = 1;
                        flag = 1;

                        furry->bull.setPosition(-100, -100);
                    }
                }

                // gamma dmg
                for (int i = 0; i < 4; i++)
                {
                    if (gg[i] != nullptr && furry->bull.getPosition().x < gg[i]->get().getPosition().x + 100 && furry->bull.getPosition().x > gg[i]->get().getPosition().x - 50 && furry->bull.getPosition().y < gg[i]->get().getPosition().y && furry->bull.getPosition().y > gg[i]->get().getPosition().y - 100)
                    {
                        death = 1;
                        delete gg[i];
                        gg[i] = nullptr;
                        bxg[i]->death = 1;
                        flag = 1;

                        furry->bull.setPosition(-100, -100);
                    }
                }

                // alpha fire
                for (int i = 0; i < 8; i++)
                {
                    if (aa[i] != nullptr)
                    {
                        aa[i]->attack(window, bxa[i]);
                    }
                    if (bxa[i] != nullptr)
                    {
                        bxa[i]->bb_fire(bxa[i], window);
                        bxa[i]->dead(bxa[i]);
                    }
                }

                // beta fire
                for (int i = 0; i < 6; i++)
                {
                    if (bb[i] != nullptr)
                    {
                        bb[i]->attack(window, bxb[i]);
                    }
                    if (bxb[i] != nullptr)
                    {
                        bxb[i]->bb_fire(bxb[i], window);
                        bxb[i]->dead(bxb[i]);
                    }
                }

                // gamma fire
                for (int i = 0; i < 4; i++)
                {
                    if (gg[i] != nullptr)
                    {
                        gg[i]->attack(window, bxg[i]);
                    }
                    if (bxg[i] != nullptr)
                    {
                        bxg[i]->bb_fire(bxg[i], window);
                        bxg[i]->dead(bxg[i]);
                    }
                }

                // alpha sprite
                for (int i = 0; i < 8; i++)
                {
                    if (aa[i] != nullptr)
                    {
                        aa[i]->draw(window);
                    }
                }

                // beta sprite
                for (int i = 0; i < 6; i++)
                {
                    if (bb[i] != nullptr)
                    {
                        bb[i]->draw(window);
                    }
                }

                // gamma sprite
                for (int i = 0; i < 4; i++)
                {
                    if (gg[i] != nullptr)
                    {
                        gg[i]->draw(window);
                    }
                }

                // level checker
                int lvl = 0;
                for (int i = 0; i < 8; i++)
                {
                    if (aa[i] == nullptr)
                        lvl++;
                }
                for (int i = 0; i < 6; i++)
                {
                    if (bb[i] == nullptr)
                        lvl++;
                }
                for (int i = 0; i < 4; i++)
                {
                    if (gg[i] == nullptr)
                        lvl++;
                }
                if (lvl == 18)
                {
                    formation = 0;
                    bb_flag = 0;
                    level++;
                    if (level == 4)
                        window.close();
                }
                // pause
                if (e.key.code == Keyboard::Escape)
                {
                    for (;;)
                    {
                        Event tt;
                        window.draw(resume);
                        window.display();
                        window.pollEvent(tt);
                        if (tt.key.code == Keyboard::Num1)
                        {
                            break;
                        }
                        if (tt.key.code == Keyboard::Num3)
                        {
                            for (;;)
                            {
                                Event rx;
                                window.draw(help);
                                window.display();
                                window.pollEvent(rx);
                                if (rx.key.code == Keyboard::H)
                                {
                                    break;
                                }
                            }
                        }
                        if (tt.key.code == Keyboard::Num4)
                        {
                            window.close();
                            break;
                        }
                    }
                }
                window.display();
            }
        }
    };