#ifndef EVENTCALLBACKPARAM2_HPP
#define EVENTCALLBACKPARAM2_HPP

#include "BaseEventCallable.hpp"
template <typename T>
class EventCallbackParam2 : public BaseEventCallable
{
    public:
        typedef void (*FunctionType)(const sf::Event& event,T& data);

        EventCallbackParam2(FunctionType call,T& data,const sf::Event &ev) : BaseEventCallable(ev), data(data)
        {
            callback = call;
        };

        EventCallbackParam2(FunctionType call,T& data,const sf::Event::EventType &evtType) : BaseEventCallable(evtType), data(data)
        {
            callback = call;
        };

        EventCallbackParam2(FunctionType call,T& data,const sf::Event::EventType &evtType,const sf::Mouse::Button button) : BaseEventCallable(evtType,button), data(data)
        {
            callback = call;
        };

        EventCallbackParam2(FunctionType call,T& data,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false) : BaseEventCallable(evtType,code,alt,ctlr,shift,system), data(data)
        {
            callback = call;
        };

        EventCallbackParam2(FunctionType call,T& data,const sf::Event::EventType &evtType,const int joyId, const int button) : BaseEventCallable(evtType,joyId,button), data(data)
        {
            callback = call;
        };

        virtual void execute(const sf::Event& ev){callback(ev,data);};

    private:
        FunctionType callback;
        T& data;
};

#endif
