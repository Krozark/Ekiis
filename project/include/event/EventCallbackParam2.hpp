#ifndef EVENTCALLBACKPARAM2_HPP
#define EVENTCALLBACKPARAM2_HPP

#include "BaseEventCallable.hpp"

class EventCallbackParam2 : public BaseEventCallable
{
    public:
        typedef void (*FunctionType)(const sf::Event& event,void* data);

        EventCallbackParam2(FunctionType call,void* data,const sf::Event &ev) : BaseEventCallable(ev)
        {
            callback = call;
            this->data = data;
        };

        EventCallbackParam2(FunctionType call,void* data,const sf::Event::EventType &evtType) : BaseEventCallable(evtType)
        {
            callback = call;
            this->data = data;
        };

        EventCallbackParam2(FunctionType call,void* data,const sf::Event::EventType &evtType,const sf::Mouse::Button button) : BaseEventCallable(evtType,button)
        {
            callback = call;
            this->data = data;
        };

        EventCallbackParam2(FunctionType call,void* data,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false) : BaseEventCallable(evtType,code,alt,ctlr,shift,system)
        {
            callback = call;
            this->data = data;
        };

        EventCallbackParam2(FunctionType call,void* data,const sf::Event::EventType &evtType,const int joyId, const int button) : BaseEventCallable(evtType,joyId,button)
        {
            callback = call;
            this->data = data;
        };

        virtual void execute(const sf::Event& ev){callback(ev,data);};

    private:
        FunctionType callback;
        void* data;
};

#endif
