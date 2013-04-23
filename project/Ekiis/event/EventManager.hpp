#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "BaseEventCallable.hpp"

#include "EventCallback.hpp"
#include "EventCallbackEvent.hpp"

#include "EventObject.hpp"
#include "EventObjectEvent.hpp"


class EventManager
{
    public:

        /************************* callback (T ... )*****************************/
        template<typename ... Args,typename ... T>
        static BaseEventCallable* createEvent(typename EventCallback<Args ...>::FunctionType call,Args...args ,T ... t)
        {
            return new EventCallback<Args ...>(call,args ..., t ...);
        };
        /************************* callback(sf::Event, T ...) *****************************/
        template<typename ... Args,typename ... T>
        static BaseEventCallable* createEvent(typename EventCallbackEvent<Args ...>::FunctionType call,Args...args,T ... t)
        {
            return new EventCallbackEvent<Args...>(call,args ...,t ...);
        };
        /***************** OBJECT.METHODE() ***************************/
        template<class C, typename ... Args,typename ... T>
        static BaseEventCallable* createEvent(C& o,typename EventObject<C,Args ...>::FunctionType call,Args ... args, T ... t)
        {
            return new EventObject<C,Args ...>(o,call,args ..., t ...);
        };

        /***************** OBJECT.METHODE(sf::Event) ***************************/
        template<class C, typename ... Args,typename ... T>
        static BaseEventCallable* createEvent(C& o,typename EventObjectEvent<C,Args ...>::FunctionType call,Args ... args, T ... t)
        {
            return new EventObjectEvent<C, Args ...>(o,call,args ..., t ...);
        };

    private:
        EventManager(){};
};

#endif
