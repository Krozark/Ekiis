#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "BaseEventCallable.hpp"
#include "EventExecutable.hpp"
#include "EventObject.hpp"
#include "EventObjectParam.hpp"

class EventManager
{
    public:

        static BaseEventCallable* createEvent(EventExecutable::FunctionType call,void* data,const sf::Event &ev){return new EventExecutable(call,data,ev);};
        static BaseEventCallable* createEvent(EventExecutable::FunctionType call,void* data,const sf::Event::EventType &evtType){return new EventExecutable(call,data,evtType);};
        static BaseEventCallable* createEvent(EventExecutable::FunctionType call,void* data,const sf::Event::EventType &evtType,const sf::Mouse::Button button){return new EventExecutable(call,data,evtType,button);};
        static BaseEventCallable* createEvent(EventExecutable::FunctionType call,void* data,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false){return new EventExecutable(call,data,evtType,code,alt,ctlr,shift,system);};
        static BaseEventCallable* createEvent(EventExecutable::FunctionType call,void* data,const sf::Event::EventType &evtType,const int joyId, const int button){return new EventExecutable(call,data,evtType,joyId,button);};

        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event& ev){return new EventObject<T>(o,f,ev);};
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event::EventType &evtType){return new EventObject<T>(o,f,evtType);};
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event::EventType &evtType,const sf::Mouse::Button button){return new EventObject<T>(o,f,evtType,button);};
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr=false, bool shift=false, bool system=false){return new EventObject<T>(o,f,evtType,code,alt,ctlr,shift,system);};
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event::EventType &evtType,const int joyId, const int button){return new EventObject<T>(o,f,evtType,joyId,button);};

        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event& ev){return new EventObjectParam<T>(o,f,ev);};
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event::EventType &evtType){return new EventObjectParam<T>(o,f,evtType);};
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event::EventType &evtType,const sf::Mouse::Button button){return new EventObjectParam<T>(o,f,evtType,button);};
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr=false, bool shift=false, bool system=false){return new EventObjectParam<T>(o,f,evtType,code,alt,ctlr,shift,system);};
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event::EventType &evtType,const int joyId, const int button){return new EventObjectParam<T>(o,f,evtType,joyId,button);};

    private:
        EventManager(){};
};

#endif
