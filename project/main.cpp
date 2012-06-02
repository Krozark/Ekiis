#include "Rect.hpp"
#include "Circle.hpp"
#include "Convex.hpp"
#include "SoftCircle.hpp"

#include "convert.h"
#include  "math.h"

#define WIDTH 1600
#define HEIGHT 900
#define BPP 32

#include <iostream>

using namespace std;
using namespace sf;
//extern world
b2World world(b2Vec2(0,-9.8f));

int main(int argc, char * argv[])
{
    // VARS
    const float32 fps = 60.0f;
    const float32 timeStep = 1.0f / fps;

    const int32 velocityIter = 8;
    const int32 positionIter = 3;

    // SFML
    RenderWindow app(VideoMode(WIDTH, HEIGHT, BPP), "Box2D");
    app.SetFramerateLimit(fps);


    // Enable Z-buffer read and write
    //glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.f);


    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(90.f, 1.f, 1.f, 500.f);


    Vector2f center(0, 0);
    Vector2f halfSize(WIDTH, HEIGHT);
    View view(center, halfSize);
    app.SetView(view); // centrage de la zone de rendu sur (0;0)
    // BOX2D


    vector<Body*> bodys(4);

    bodys[0] = new RectBody(0,300,10000,10,b2_staticBody);
    bodys[0]->SetRotation(25);

    bodys[1] = new RectBody(300,0,10000,10,b2_staticBody);
    bodys[1]->SetRotation(90);

    bodys[2] = new RectBody(0,-3500,10000,10,b2_staticBody);
    bodys[2]->SetRotation(180);

    bodys[3] = new RectBody(-400,0,10000,10,b2_staticBody);
    bodys[3]->SetRotation(90);

     GLuint texture = 0;
    {
        sf::Image image;
        if (!image.LoadFromFile("b.png"))
            exit(1);
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.GetWidth(), image.GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, image.GetPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glDisable(GL_TEXTURE_2D);

    }

    // MAIN LOOP
    while(app.IsOpen())
    {
        Event event; // gestion des évenements
        while(app.PollEvent(event))
        {
            if(event.Type == sf::Event::Closed)
                app.Close();
            else if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Keyboard::Escape))
                app.Close();
            else if ((event.Type == sf::Event::MouseButtonPressed) && (event.MouseButton.Button == sf::Mouse::Left)){
                Vector2i pos = sf::Mouse::GetPosition(app);
                float nb = (rand()/((double)RAND_MAX))*60+30;
                SoftCircle* n = (new SoftCircle(pos.x-WIDTH/2,pos.y-HEIGHT/2,nb,0.5,32));
                n->SetTexture(texture);
                bodys.push_back(n);
            }
            else if ((event.Type == sf::Event::MouseButtonPressed) && (event.MouseButton.Button == sf::Mouse::Right)){
                 Vector2i pos = sf::Mouse::GetPosition(app);
                 float nb = (rand()/((double)RAND_MAX))*60+30;
                 Body* n= new CircleBody(pos.x-WIDTH/2,pos.y-HEIGHT/2,nb);
                 bodys.push_back(n);
            }
        }

        world.Step(timeStep, velocityIter, positionIter); // on calcule la frame suivante

        app.Clear();

        /*{

            b2Body* b = world.GetBodyList();//get start of list
            while ( b != NULL )
            {
              Body* body = static_cast<Body*>( b->GetUserData() );
              if ( body != NULL )
                    body->Draw(app);
              //continue to next body
              b = b->GetNext();
            }
        }*/

        for (int i =bodys.size()-1;i>=0;--i)
                bodys[i]->Draw(app);

        /*{
            b2Joint* b =world.GetJointList ();
            while ( b != NULL )
            {

              Vector2f A(toPix(b->GetAnchorA ().x),toPix(-b->GetAnchorA ().y));
              Vector2f B(toPix(b->GetAnchorB ().x),toPix(-b->GetAnchorB ().y));

              ConvexShape s(4);

              s.SetPoint(0,A);
              s.SetPoint(1,B);
              s.SetPoint(2,B);
              s.SetPoint(3,A);

              s.SetOutlineColor(Color::Yellow);
              s.SetOutlineThickness(0.2);

              app.Draw(s);

              //continue to next body
              b = b->GetNext();
            }
        }*/
        app.Display();
    }
    glDeleteTextures(1, &texture);
    return EXIT_SUCCESS;
}
