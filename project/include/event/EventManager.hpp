#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "event.hpp"


class EventManager
{
    public:

        /************************* callback() *****************************/
        static BaseEventCallable* createEvent(EventCallback::FunctionType call,const sf::Event &ev)
        {
            return new EventCallback(call,ev);
        };
        static BaseEventCallable* createEvent(EventCallback::FunctionType call,const sf::Event::EventType &evtType)
        {
            return new EventCallback(call,evtType);
        };
        static BaseEventCallable* createEvent(EventCallback::FunctionType call,const sf::Event::EventType &evtType,const sf::Mouse::Button button)
        {
            return new EventCallback(call,evtType,button);
        };
        static BaseEventCallable* createEvent(EventCallback::FunctionType call,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false)
        {
            return new EventCallback(call,evtType,code,alt,ctlr,shift,system);
        };
        static BaseEventCallable* createEvent(EventCallback::FunctionType call,const sf::Event::EventType &evtType,const int joyId, const int button)
        {
            return new EventCallback(call,evtType,joyId,button);
        };

        /************************* callback(sf::Event) *****************************/
        static BaseEventCallable* createEvent(EventCallbackParam::FunctionType call,const sf::Event &ev)
        {
            return new EventCallbackParam(call,ev);
        };
        static BaseEventCallable* createEvent(EventCallbackParam::FunctionType call,const sf::Event::EventType &evtType)
        {
            return new EventCallbackParam(call,evtType);
        };
        static BaseEventCallable* createEvent(EventCallbackParam::FunctionType call,const sf::Event::EventType &evtType,const sf::Mouse::Button button)
        {
            return new EventCallbackParam(call,evtType,button);
        };
        static BaseEventCallable* createEvent(EventCallbackParam::FunctionType call,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false)
        {
            return new EventCallbackParam(call,evtType,code,alt,ctlr,shift,system);
        };
        static BaseEventCallable* createEvent(EventCallbackParam::FunctionType call,const sf::Event::EventType &evtType,const int joyId, const int button)
        {
            return new EventCallbackParam(call,evtType,joyId,button);
        };

         /************************* callback(sf::Event,T&) *****************************/
        template<typename T>
        static BaseEventCallable* createEvent(void (*FunctionType)(const sf::Event& event,T& data),T& data,const sf::Event &ev)
        {
            return new EventCallbackParam2<T>(FunctionType,data,ev);
        };
        template<typename T>
        static BaseEventCallable* createEvent(void (*FunctionType)(const sf::Event& event,T& data),T& data,const sf::Event::EventType &evtType)
        {
            return new EventCallbackParam2<T>(FunctionType,data,evtType);
        };
        template<typename T>
        static BaseEventCallable* createEvent(void (*FunctionType)(const sf::Event& event,T& data),T& data,const sf::Event::EventType &evtType,const sf::Mouse::Button button)
        {
            return new EventCallbackParam2<T>(FunctionType,data,evtType,button);
        };
        template<typename T>
        static BaseEventCallable* createEvent(void (*FunctionType)(const sf::Event& event,T& data),T& data,const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr = false, bool shift = false, bool system = false)
        {
            return new EventCallbackParam2<T>(FunctionType,data,evtType,code,alt,ctlr,shift,system);
        };
        template<typename T>
        static BaseEventCallable* createEvent(void (*FunctionType)(const sf::Event& event,T& data),T& data,const sf::Event::EventType &evtType,const int joyId, const int button)
        {
            return new EventCallbackParam2<T>(FunctionType,data,evtType,joyId,button);
        };

        /***************** OBJECT.METHODE() ***************************/
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

        /***************** OBJECT.METHODE(sf::Event) ***************************/
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

    private:
        EventManager(){};
};

#endif
