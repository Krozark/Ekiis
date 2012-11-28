#ifndef EVENTEXECUTABLE_HPP
#define EVENTEXECUTABLE_HPP

#include "BaseEventCallable.hpp"

class EventExecutable : public BaseEventCallable
{
    public:
        EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event &ev);
        EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event::EventType &evtType);
        EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event::EventType &evtType,const sf::Mouse::Button button);
        EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false);
        EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event::EventType &evtType,const int joyId, const int button);

        virtual void execute(const sf::Event& ev){callback(ev,data);};

    private:
        void (*callback)(const sf::Event& event,void* data);
        void* data;
};

#endif
