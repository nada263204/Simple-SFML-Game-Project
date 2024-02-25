#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace sf;
using namespace std;

struct point
{ int x,y;};

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(600, 600), "MONSTERS Game!");
    app.setFramerateLimit(60);

    sf:: Music music ;
    if(!music.openFromFile("main.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }

  music.play();



    Texture t1,t2,t3;
    t1.loadFromFile("back.jpg");
    t2.loadFromFile("platform.png");
    t3.loadFromFile("otty.png");



    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    point plat[20];

    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

    int x=100,y=100,h=200;
    float dx=0,dy=0;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

    dy+=0.2;
    y+=dy;
    if (y>500)  dy=-10;

    if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
    }

    for (int i=0;i<10;i++)
     if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
      && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))  dy=-10;

    sPers.setPosition(x,y);
    sPers.setScale(0.08,0.08);



    app.draw(sBackground);

    app.draw(sPers);
    for (int i=0;i<10;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    sPlat.setScale(1,1);
    app.draw(sPlat);
    }

    app.display();
}

    return 0;
}
