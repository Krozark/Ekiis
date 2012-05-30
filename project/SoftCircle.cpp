#include "SoftCircle.hpp"
#include "Circle.hpp"
#include  "math.h"
#include <SFML/OpenGL.hpp>

//#include <iostream>


using namespace sf;
//using namespace std;

SoftCircle::SoftCircle(float posx,float posy,float rayon,float duretee,const unsigned int quality): Body(posx,posy), nb_circles(quality>16?quality:16), texture(0)
{
    if (duretee >1)
        duretee = 1;
    else if (duretee<0)
        duretee=0;
  // Determine part radius
    const float angleStep = (pi * 2.0f) / nb_circles;
    const float sinHalfAngle = sinf(angleStep * 0.5f);
    const float subCircleRadius = sinHalfAngle * rayon / (1.0f + sinHalfAngle);
    float radius = (rayon - subCircleRadius * 2.0f) * (1.0f - duretee);

    /// create the centre circle
    shape = new CircleShape(radius);
    b2shape = new b2CircleShape;
    static_cast<b2CircleShape*>(b2shape)->m_p.Set(0,0); //position, relative to body position
    static_cast<b2CircleShape*>(b2shape)->m_radius = toMet(radius); //radius

    fixtureDef.shape = b2shape;
    fixture=body->CreateFixture(&fixtureDef);

    shape->SetOrigin(radius,radius);
    SetPosition(posx,posy);
    SetColor(Color::Red);

    /// create the other
    bodys = new Body*[nb_circles];
    textcoord  = new fpoint[nb_circles];

    {
        float angle = 0;
        for (unsigned int i=0;i<nb_circles;++i)
        {
            float c = cos(angle);
            float s = sin(angle);

            bodys[i] = new CircleBody(
                          c*(rayon-subCircleRadius)+posx,
                          s*(rayon-subCircleRadius)+posy,
                          subCircleRadius);
            ///TODO
            if (angle <= pi/4) // 45
            {
                textcoord[i].x = 1;
                textcoord[i].y = tan(angle);

            }
            else if (angle <=2.0*pi/4.0 ) //90
            {
                textcoord[i].x = 1-tan(angle-pi/4.0);
                textcoord[i].y = 1;
            }
            else if (angle  <= 3.0*pi/4 ) //135
            {
                textcoord[i].x = -tan(angle-2.0*pi/4.0);
                textcoord[i].y = 1;

            }
            else if (angle  <= pi) //180
            {
                textcoord[i].x = -1;
                textcoord[i].y = - tan(angle);
            }
            else if (angle  <= 5.0*pi/4.0 ) //225
            {
                textcoord[i].x = -1;
                textcoord[i].y = -tan(angle);

            }
            else if (angle  <= 6.0*pi/4.0) //270
            {
                textcoord[i].x = tan(angle - pi/4.0)-1;
                textcoord[i].y = -1;
            }
            else if (angle  <= 7.0*pi/4.0) //315
            {
                textcoord[i].x = tan(angle -6.0*pi/4.0);
                textcoord[i].y = -1;

            }
            else //360
            {
                textcoord[i].x = 1;
                textcoord[i].y = -(1-tan(angle-3.0*pi/4.0));
            }

            //cout<<float(toDeg(angle))<<"\t|\t"<<"\t"<<textcoord[i].x<<"\t"<<textcoord[i].y<<"\t\t|\t";
            textcoord[i].x = (1 + textcoord[i].x)/2 ;
            textcoord[i].y = (1 + textcoord[i].y)/2;

            //cout<<textcoord[i].x<<"\t"<<textcoord[i].y<<endl;

            angle += angleStep;
        }
    }
    // join together
    b2DistanceJointDef jointDef;
    for (unsigned int i=0;i<nb_circles;++i)
    {
        const int neighborIndex = (i + 1)< nb_circles?i+1:0;
        bodys[i]->DistanceJoinWith(*this,10-duretee*10);
        bodys[i]->DistanceJoinWith(*bodys[neighborIndex],0);

    }
};

void SoftCircle::Draw(sf::RenderTarget& window)
{
    if (texture)
    {
     glBindTexture(GL_TEXTURE_2D, texture);
     glEnable(GL_TEXTURE_2D);
    }

    // Bind our texture
    glClear(GL_DEPTH_BUFFER_BIT);
    glColor4f(1.f, 1.f, 1.f, 1.f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    #define z -100
    glTranslatef(0,0, z);

    glBegin(GL_TRIANGLE_FAN);
            b2Vec2 origine = body->GetPosition();
            glTexCoord2f(0.5, 0.5);
            glVertex3f(toPix(origine.x),-toPix(origine.y), -z);

            for(unsigned int i=0;i<nb_circles;++i)
            {
                b2Vec2 centre = bodys[i]->body->GetPosition();
                centre += (1.0/6)*(centre -  origine);
                glTexCoord2f(textcoord[i].x, textcoord[i].y);
                glVertex3f(toPix(centre.x),-toPix(centre.y), -z);
            }
            b2Vec2 centre = bodys[0]->body->GetPosition();
            centre += (1.0/6)*(centre -  origine);
            glTexCoord2f(textcoord[0].x, textcoord[0].y);
            glVertex3f(toPix(centre.x),-toPix(centre.y), -z);

    glEnd();

    glDisable(GL_TEXTURE_2D);

};

SoftCircle::~SoftCircle()
{
    for (unsigned int i=0; i<nb_circles;++i)
        delete bodys[i];
    delete bodys;

    delete textcoord;
};
