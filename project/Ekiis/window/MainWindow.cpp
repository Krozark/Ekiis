#include <SFML/OpenGL.hpp>

#include "MainWindow.hpp"
#include "../Event/src/Event/EventManager.hpp"


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
    addEvent(EventManager::createEventObj(*this,&MainWindow::resizeSlot,sf::Event::Resized));
    addEvent(EventManager::createEventObj<MainWindow,float,float>(*this,&MainWindow::moveView,1.f,0.f,sf::Event::KeyPressed,sf::Keyboard::Right),true);
    addEvent(EventManager::createEventObj<MainWindow,float,float>(*this,&MainWindow::moveView,-1.f,0.f,sf::Event::KeyPressed,sf::Keyboard::Left),true);
    addEvent(EventManager::createEventObj<MainWindow,float,float>(*this,&MainWindow::moveView,0.f,1.f,sf::Event::KeyPressed,sf::Keyboard::Down),true);
    addEvent(EventManager::createEventObj<MainWindow,float,float>(*this,&MainWindow::moveView,0.f,-1.f,sf::Event::KeyPressed,sf::Keyboard::Up),true);
    elapsedTime=0;
};

MainWindow::~MainWindow()
{
    int size = events.size();
    for (int i=0;i<size;++i)
        delete events[i];
};

void MainWindow::addCloseEvent()
{
    addEvent(EventManager::createEventObj(*this,&MainWindow::close,sf::Event::Closed));
    addEvent(EventManager::createEventObj(*this,&MainWindow::close,sf::Event::KeyPressed,sf::Keyboard::Escape));
};

void MainWindow::resizeSlot(const sf::Event& event)
{
    sf::View view = getView();
    view.setSize(event.size.width,event.size.height);
    setView(view);
};


void MainWindow::moveView(float x,float y)
{
    sf::View view = getView();
    view.move(x*elapsedTime,y*elapsedTime);
    setView(view);
};

void MainWindow::doEvents()
{

    Event event; // gestion des évenements
    elapsedTime =  LoopClock.restart().asMilliseconds();

    int size = events.size();
    for (int i=0;i<size;++i)
        if (events[i]->test())
            events[i]->execute(event);

    size = momentEvents.size();
    while(this->pollEvent(event))
    {
        for (int i=0;i<size;++i)
            if (*momentEvents[i] == event)
            {
                momentEvents[i]->execute(event);
                //break;
            }
    }
};
