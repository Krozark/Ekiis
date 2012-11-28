#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <SFML/Graphics.hpp>
#include "BaseEventCallable.hpp"

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(const sf::VideoMode mode, const std::string &title,const unsigned int max_fps=60);

        inline void addEvent(BaseEventCallable* ev){events.push_back(ev);};

        /*
        inline void addEvent(void (*call)(MainWindow& w,const sf::Event& event),sf::Event &ev){events.push_back(EventExecutable(call,ev));};
        inline void addEvent(void (*call)(MainWindow& w,const sf::Event& event),const sf::Event::EventType &evtType){events.push_back(EventExecutable(call,evtType));};;
        inline void addEvent(void (*call)(MainWindow& w,const sf::Event& event),const sf::Event::EventType &evtType,const sf::Mouse::Button button){events.push_back(EventExecutable(call,evtType,button));};;
        inline void addEvent(void (*call)(MainWindow& w,const sf::Event& event),const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false,bool ctlr = false,bool shift = false,bool system = false){events.push_back(EventExecutable(call,evtType,code,alt,ctlr,shift,system));};
        inline void addEvent(void (*call)(MainWindow& w,const sf::Event& event),const sf::Event::EventType &evtType,const int joyId, const int button){events.push_back(EventExecutable(call,evtType,joyId,button));};
        */
        void addCloseEvent();
        void doEvents();

    private:
        std::vector<BaseEventCallable*> events;
};

#endif
