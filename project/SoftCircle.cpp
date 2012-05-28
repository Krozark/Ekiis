#include "SoftCircle.hpp"
#include "Circle.hpp"
#include  "math.h"
#include <SFML/OpenGL.hpp>
/*

*/

using namespace sf;

SoftCircle::SoftCircle(float posx,float posy,float rayon): Body(posx,posy), nb_circles(20)
{
  // Determine part radius
    const float angleStep = (pi * 2.0f) / nb_circles;
    const float sinHalfAngle = sinf(angleStep * 0.5f);
    const float subCircleRadius = sinHalfAngle * rayon / (1.0f + sinHalfAngle);
    float radius = (rayon - subCircleRadius * 2.0f) * (1.0f - 0.7);

    /// create the centre circle
    shape = new CircleShape(rayon);
    b2shape = new b2CircleShape;
    static_cast<b2CircleShape*>(b2shape)->m_p.Set(0,0); //position, relative to body position
    static_cast<b2CircleShape*>(b2shape)->m_radius = toMet(radius); //radius

    fixtureDef.shape = b2shape;
    fixture=body->CreateFixture(&fixtureDef);

    shape->SetOrigin(rayon,rayon);
    SetPosition(posx,posy);
    SetColor(Color::Red);

    /// create the other
    bodys = new Body*[nb_circles];
    textcoord  = new fpoint[nb_circles];

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
        textcoord[i].x = c*rayon + posx;
        textcoord[i].y = s*rayon + posy;

        angle += angleStep;
    }

    // join together
    b2DistanceJointDef jointDef;
    for (unsigned int i=0;i<nb_circles;++i)
    {
        const int neighborIndex = (i + 1)< nb_circles?i+1:0;
        bodys[i]->DistanceJoinWith(*this,5);
        bodys[i]->DistanceJoinWith(*bodys[neighborIndex],10);
    }
};

void SoftCircle::Draw(sf::RenderTarget& window)
{

    /*GLuint texture = 0;
    {
        sf::Image image;
        if (!image.LoadFromFile("b.png"))
            return;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.GetWidth(), image.GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, image.GetPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    }


    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(10.f);

    // Bind our texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glColor4f(1.f, 1.f, 1.f, 1.f);

    //window.SetActive();
    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glTranslatef(0,0, -10.0f); /// position


    glBegin(GL_TRIANGLE_STRIP);

            glTexCoord2f(textcoord[nb_circles-1].x, textcoord[nb_circles-1].y); glVertex3f(-1, -1, 10);
            glTexCoord2f(0.5, 0.5); glVertex3f(0, 0, 10);

            for(unsigned int i=0;i<nb_circles;++i)
            {
                glTexCoord2f(textcoord[i].x, textcoord[i].y); glVertex3f(-size, -size, 10);
            }


    glEnd();

    glDeleteTextures(1, &texture);
*/
    //window.Draw(*shape);
};

SoftCircle::~SoftCircle()
{
    for (unsigned int i=0; i<nb_circles;++i)
        delete bodys[i];
    delete bodys;

    delete textcoord;
};
