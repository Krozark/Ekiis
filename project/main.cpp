#define WIDTH 1600
#define HEIGHT 900
#define BPP 32

#include <iostream>
#include "window.hpp"
#include "body.hpp"
#include "event/EventManager.hpp"

using namespace std;
using namespace sf;
//extern world
b2World world(b2Vec2(0,-9.8f));

vector<Body*> bodys(4);
GLuint texture = 0;

static void addSoftCircleCallBack(const sf::Event& event)
{
    float nb = (rand()/((double)RAND_MAX))*60+30;
    SoftCircle* n = (new SoftCircle(event.mouseButton.x-WIDTH/2,event.mouseButton.y-HEIGHT/2,nb,0.5,32));
    n->SetTexture(texture);
    bodys.push_back(n);
};

static void addCircleCallBack(const sf::Event& event)
{
     float nb = (rand()/((double)RAND_MAX))*60+30;
     Body* n= new CircleBody(event.mouseButton.x-WIDTH/2,event.mouseButton.y-HEIGHT/2,nb);
     bodys.push_back(n);
};

static void addEntityCallBack(const sf::Event& event,void* data)
{
    Vector2i pos = sf::Mouse::getPosition(*static_cast<sf::Window*>(data));
    Body* n =new Entity(pos.x-WIDTH/2,pos.y-HEIGHT/2);
    bodys.push_back(n);
};

int main(int argc, char * argv[])
{
    // VARS
    const float32 fps = 60.0f;
    const float32 timeStep = 1.0f / fps;

    const int32 velocityIter = 8;
    const int32 positionIter = 3;

    // SFML
    MainWindow app(VideoMode(WIDTH, HEIGHT, BPP), "Box2D",60);
    app.addEvent(EventManager::createEvent(addSoftCircleCallBack,sf::Event::MouseButtonPressed,sf::Mouse::Left));
    app.addEvent(EventManager::createEvent(addCircleCallBack,sf::Event::MouseButtonPressed,sf::Mouse::Right));
    app.addEvent(EventManager::createEvent(addEntityCallBack,&app,sf::Event::KeyPressed,sf::Keyboard::Space));


    // BOX2D

    bodys[0] = new RectBody(0,300,10000,10,b2_staticBody);
    bodys[0]->SetRotation(25);

    bodys[1] = new RectBody(300,0,10000,10,b2_staticBody);
    bodys[1]->SetRotation(90);

    bodys[2] = new RectBody(0,-3500,10000,10,b2_staticBody);
    bodys[2]->SetRotation(180);

    bodys[3] = new RectBody(-400,0,10000,10,b2_staticBody);
    bodys[3]->SetRotation(90);


    {
        sf::Image image;
        if (!image.loadFromFile("b.png"))
            exit(1);
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        Vector2u size = image.getSize();
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, size.x, size.y, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glDisable(GL_TEXTURE_2D);

    }

    // MAIN LOOP
    while(app.isOpen())
    {
        app.doEvents();

        world.Step(timeStep, velocityIter, positionIter); // on calcule la frame suivante

        app.clear();

        for (int i =bodys.size()-1;i>=0;--i)
                bodys[i]->Draw(app);

        app.display();
    }
    glDeleteTextures(1, &texture);
    return EXIT_SUCCESS;
}
