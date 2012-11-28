#ifndef EVENTOBJECT_HPP
#define EVENTOBJECT_HPP

#include "BaseEventCallable.hpp"

template<typename T>
class EventObject : public BaseEventCallable
{
    typedef void (T::*FunctionType)(/*sf::Event& event*/);
    public:
       /* EventObject(T* obj,FunctionType methode,const sf::Event& ev): BaseEventCallable(ev)
        {
            this->obj = obj;
            this->callback = methode;
        };*/

        EventObject(T* obj,FunctionType methode,const sf::Event::EventType &evtType)  : BaseEventCallable(evtType)
        {
            this->obj = obj;
            this->callback = methode;
        };

        /*EventObject(T* obj,FunctionType methode,const sf::Event::EventType &evtType,const sf::Mouse::Button button) : BaseEventCallable(evtType,button)
        {
            this->obj = obj;
            this->callback = methode;
        };

        EventObject(T* obj,FunctionType methode,const sf::Event::EventType &evtType,const sf::Keyboard::Key code=false, bool alt=false, bool ctlr=false, bool shift=false, bool system=false) : BaseEventCallable(evtType,code,alt,ctlr,shift,system)
        {
            this->obj = obj;
            this->callback = methode;
        };

        EventObject(T* obj,FunctionType methode,const sf::Event::EventType &evtType,const int joyId, const int button) : BaseEventCallable(evtType,joyId,button)
        {
            this->obj = obj;
            this->callback = methode;
        };*/

        virtual void execute(const sf::Event& ev){(obj->*callback)();};

    private:
        T* obj;
        FunctionType callback;
};


#endif
