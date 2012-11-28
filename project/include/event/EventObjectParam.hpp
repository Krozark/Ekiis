#ifndef EVENTOBJECTPARAM_HPP
#define EVENTOBJECTPARAM_HPP

#include "BaseEventCallable.hpp"

template<typename T>
class EventObjectParam : public BaseEventCallable
{
    typedef void (T::*FunctionType)(const sf::Event& ev);
    public:
        EventObjectParam(T* obj,FunctionType methode,const sf::Event& ev): BaseEventCallable(ev)
        {
            this->obj = obj;
            this->callback = methode;
        };

        EventObjectParam(T* obj,FunctionType methode,const sf::Event::EventType &evtType)  : BaseEventCallable(evtType)
        {
            this->obj = obj;
            this->callback = methode;
        };

        EventObjectParam(T* obj,FunctionType methode,const sf::Event::EventType &evtType,const sf::Mouse::Button button) : BaseEventCallable(evtType,button)
        {
            this->obj = obj;
            this->callback = methode;
        };

        EventObjectParam(T* obj,FunctionType methode,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr=false, bool shift=false, bool system=false) : BaseEventCallable(evtType,code,alt,ctlr,shift,system)
        {
            this->obj = obj;
            this->callback = methode;
        };

        EventObjectParam(T* obj,FunctionType methode,const sf::Event::EventType &evtType,const int joyId, const int button) : BaseEventCallable(evtType,joyId,button)
        {
            this->obj = obj;
            this->callback = methode;
        };

        virtual void execute(const sf::Event& ev){(obj->*callback)(ev);};

    private:
        T* obj;
        FunctionType callback;
};


#endif
