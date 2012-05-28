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


    Vector2f center(0, 0);
    Vector2f halfSize(WIDTH/2, HEIGHT/2);
    View view(center, halfSize);
    app.SetView(view); // centrage de la zone de rendu sur (0;0)
    // BOX2D


    RectBody* ground[4];

    ground[0] = new RectBody(0,200,1000,10,b2_staticBody);
    ground[1] = new RectBody(200,0,1000,10,b2_staticBody);
    ground[2] = new RectBody(0,-200,1000,10,b2_staticBody);
    ground[3] = new RectBody(-200,0,1000,10,b2_staticBody);

    for (unsigned int i=0;i<4;++i)
    {
        ground[i]->SetColor(Color::Cyan);
        ground[i]->SetRotation(i*(90-5));
        ground[i]->SetFriction(1);
    }

    Vector2f vertices[4];
    vertices[0].x=-10*3;vertices[0].y=20*3;
    vertices[1].x=-10*3;vertices[1].y=0;
    vertices[2].x=0;vertices[2].y=-30*3;
    vertices[3].x=10*3;vertices[3].y=0;
    vertices[4].x= 10*3;vertices[4].y=10*3;


    //new CircleBody(0,0,15);


    new SoftCircle(5,-160,40);
    new SoftCircle(20,-100,30);

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
        }

        world.Step(timeStep, velocityIter, positionIter); // on calcule la frame suivante

        app.Clear();
        {

            b2Body* b = world.GetBodyList();//get start of list
            while ( b != NULL )
            {
              Body* body = static_cast<Body*>( b->GetUserData() );
              if ( body != NULL )
              {
                    body->Next();
                    body->Draw(app);
              }
              //continue to next body
              b = b->GetNext();
            }
        }

        {
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
        }

        app.Display();
    }

    return EXIT_SUCCESS;
}
