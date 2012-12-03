#ifndef EVENTCALLBACKEVENT_HPP
#define EVENTCALLBACKEVENT_HPP

#include "BaseEventCallable.hpp"

template<typename ... Args>
class EventCallbackEvent : public BaseEventCallable
{
    public:
        typedef void (*FunctionType)(const sf::Event&,Args...);
        template<typename ...T>
        EventCallbackEvent(FunctionType call,Args... args,const T ... t) :BaseEventCallable(t...), params(std::make_tuple(args ...)), callback(call) {};

        virtual void execute(const sf::Event& ev){apply(callback,ev,params);};

    private:
        FunctionType callback;
        std::tuple<Args...> params;
};

#endif
