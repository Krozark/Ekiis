#ifndef BASEEVENTCALLABLE_HPP
#define BASEEVENTCALLABLE_HPP

#include <SFML/Window/Event.hpp>

class MainWindow;

class BaseEventCallable
{
    public:
        BaseEventCallable(const sf::Event& ev);
        BaseEventCallable(const sf::Event::EventType &evtType);
        BaseEventCallable(const sf::Event::EventType &evtType,const sf::Mouse::Button button);
        BaseEventCallable(const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt, bool ctlr, bool shift, bool system);
        BaseEventCallable(const sf::Event::EventType &evtType,const int joyId, const int button);

        virtual void execute(const sf::Event& event) = 0;

        bool operator == (const sf::Event& other)const;

    protected:
        friend class MainWindow;
        sf::Event event;
};

#endif
