#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "event.hpp"


class EventManager
{
    public:

        /************************* callback (T ... )*****************************/
        template<typename ... Args,typename ... T>
        static BaseEventCallable* createEvent(typename EventCallbackParam<Args ...>::FunctionType call,Args...args ,T ... t)
        {
            return new EventCallbackParam<Args ...>(call,args ..., t ...);
        };
        /************************* callback(sf::Event, T ...) *****************************/
        template<typename ... Args,typename ... T>
        static BaseEventCallable* createEvent(typename EventCallbackParamEvent<Args ...>::FunctionType call,Args...args,T ... t)
        {
            return new EventCallbackParamEvent<Args...>(call,args ...,t ...);
        };
        /***************** OBJECT.METHODE() ***************************/
        /*
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event& ev)
        {
            return new EventObject<T>(o,f,ev);
        };
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event::EventType &evtType)
        {
            return new EventObject<T>(o,f,evtType);
        };
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event::EventType &evtType,const sf::Mouse::Button button)
        {
            return new EventObject<T>(o,f,evtType,button);
        };
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr=false, bool shift=false, bool system=false)
        {
            return new EventObject<T>(o,f,evtType,code,alt,ctlr,shift,system);
        };
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(),const sf::Event::EventType &evtType,const int joyId, const int button)
        {
            return new EventObject<T>(o,f,evtType,joyId,button);
        };
*/
        /***************** OBJECT.METHODE(sf::Event) ***************************/
        /*
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event& ev)
        {
            return new EventObjectParam<T>(o,f,ev);
        };
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event::EventType &evtType)
        {
            return new EventObjectParam<T>(o,f,evtType);
        };
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event::EventType &evtType,const sf::Mouse::Button button)
        {
            return new EventObjectParam<T>(o,f,evtType,button);
        };
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr=false, bool shift=false, bool system=false)
        {
            return new EventObjectParam<T>(o,f,evtType,code,alt,ctlr,shift,system);
        };
        template<typename T>
        static BaseEventCallable* createEvent(T* o,void (T::*f)(const sf::Event& ev),const sf::Event::EventType &evtType,const int joyId, const int button)
        {
            return new EventObjectParam<T>(o,f,evtType,joyId,button);
        };
*/
    private:
        EventManager(){};
};

#endif
