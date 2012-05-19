#include "Convex.hpp"

using namespace sf;


ConvexBody::ConvexBody (float posx,float posy,const Vector2f *vertices,int vertexCount,b2BodyType type) : Body(posx,posy,type)
{

    shape = new ConvexShape(vertexCount);
    b2shape = new b2PolygonShape;

    b2Vec2 vertices_met[vertexCount];

    for (int i=0; i< vertexCount;++i)
    {
        int j = vertexCount-i-1;
        vertices_met[j].x = toMet(vertices[i].x);
        vertices_met[j].y = -toMet(vertices[i].y);

        static_cast<ConvexShape*>(shape)->SetPoint(i,Vector2f(vertices[i].x,vertices[i].y));
    }

    static_cast<b2PolygonShape*>(b2shape)->Set(vertices_met,vertexCount);

    fixtureDef.shape = b2shape;
    fixture=body->CreateFixture(&fixtureDef);

    //set the centre
    b2Vec2 centroid = static_cast<b2PolygonShape*>(b2shape)->m_centroid;
    shape->SetOrigin(toPix(centroid.x),-toPix(centroid.y));

    SetPosition(posx,posy);

    shape->SetFillColor(Color::White);
};

