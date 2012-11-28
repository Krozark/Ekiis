#include "EventExecutable.hpp"

EventExecutable::EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event &ev) : BaseEventCallable(ev)
{
    callback = call;
    this->data = data;
};

EventExecutable::EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event::EventType &evtType) : BaseEventCallable(evtType)
{
    callback = call;
    this->data = data;
};

EventExecutable::EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt, bool ctlr, bool shift, bool system) : BaseEventCallable(evtType,code,alt,ctlr,shift,system)
{
    callback = call;
    this->data = data;
};

EventExecutable::EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event::EventType &evtType,const sf::Mouse::Button button) : BaseEventCallable(evtType,button)
{
    callback = call;
    this->data = data;
};

EventExecutable::EventExecutable(void (*call)(const sf::Event& event,void* data),void* data,const sf::Event::EventType &evtType,const int joyId, const int button) : BaseEventCallable(evtType,joyId,button)
{
    callback = call;
    this->data = data;
};

