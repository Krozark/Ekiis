#include <SFML/OpenGL.hpp>

#include "window/MainWindow.hpp"
#include "event/EventManager.hpp"


using namespace sf;

MainWindow::MainWindow(const sf::VideoMode mode, const std::string &title,const unsigned int fps) : RenderWindow(mode,title)
{
    setFramerateLimit(fps);

    // Enable Z-buffer read and write
    //glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.f);


    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(90.f, 1.f, 1.f, 500.f);

    Vector2f center(0, 0);
    Vector2f halfSize(mode.width, mode.height);
    View view(center, halfSize);
    this->setView(view); // centrage de la zone de rendu sur (0;0)

    addCloseEvent();
};

MainWindow::~MainWindow()
{
    int size = events.size();
    for (int i=0;i<size;++i)
        delete events[i];
};

void MainWindow::addCloseEvent()
{
    BaseEventCallable* ev;
    //ev= new EventExecutable(closeCallBack,this,sf::Event::Closed);
    ev = EventManager::createEvent<MainWindow>(this,&MainWindow::close,sf::Event::Closed);
    events.push_back(ev);

    ev = EventManager::createEvent<MainWindow>(this,&MainWindow::close,sf::Event::KeyPressed,sf::Keyboard::Escape);
    events.push_back(ev);
};


void MainWindow::doEvents()
{

    Event event; // gestion des évenements
    int size = events.size();
    while(this->pollEvent(event))
    {
        for (int i=0;i<size;++i)
            if (*events[i] == event)
                events[i]->execute(event);
    }

};
