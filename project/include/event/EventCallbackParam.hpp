#ifndef EVENTCALLBACKPARAM_HPP
#define EVENTCALLBACKPARAM_HPP

#include "BaseEventCallable.hpp"

class EventCallbackParam : public BaseEventCallable
{
    public:
        typedef void (*FunctionType)(const sf::Event& event);

        EventCallbackParam(FunctionType call,const sf::Event &ev) : BaseEventCallable(ev)
        {
            callback = call;
        };

        EventCallbackParam(FunctionType call,const sf::Event::EventType &evtType) : BaseEventCallable(evtType)
        {
            callback = call;
        };

        EventCallbackParam(FunctionType call,const sf::Event::EventType &evtType,const sf::Mouse::Button button) : BaseEventCallable(evtType,button)
        {
            callback = call;
        };

        EventCallbackParam(FunctionType call,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false) : BaseEventCallable(evtType,code,alt,ctlr,shift,system)
        {
            callback = call;
        };

        EventCallbackParam(FunctionType call,const sf::Event::EventType &evtType,const int joyId, const int button) : BaseEventCallable(evtType,joyId,button)
        {
            callback = call;
        };

        virtual void execute(const sf::Event& ev){callback(ev);};

    private:
        FunctionType callback;
};

#endif
