#ifndef EVENTCALLBACK_HPP
#define EVENTCALLBACK_HPP

#include "BaseEventCallable.hpp"

class EventCallback : public BaseEventCallable
{
    public:
        typedef void (*FunctionType)();

        EventCallback(FunctionType call,const sf::Event &ev) : BaseEventCallable(ev)
        {
            callback = call;
        };

        EventCallback(FunctionType call,const sf::Event::EventType &evtType) : BaseEventCallable(evtType)
        {
            callback = call;
        };

        EventCallback(FunctionType call,const sf::Event::EventType &evtType,const sf::Mouse::Button button) : BaseEventCallable(evtType,button)
        {
            callback = call;
        };

        EventCallback(FunctionType call,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false) : BaseEventCallable(evtType,code,alt,ctlr,shift,system)
        {
            callback = call;
        };

        EventCallback(FunctionType call,const sf::Event::EventType &evtType,const int joyId, const int button) : BaseEventCallable(evtType,joyId,button)
        {
            callback = call;
        };

        virtual void execute(const sf::Event& ev){callback();};

    private:
        FunctionType callback;
};

#endif
