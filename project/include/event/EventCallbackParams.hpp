#ifndef EVENTCALLBACKPARAMSEVENT_HPP
#define EVENTCALLBACKPARAMSEVENT_HPP

#include "BaseEventCallable.hpp"

template<typename ... Args>
class EventCallbackParamsEvent : public BaseEventCallable
{
    public:
        typedef void (*FunctionType)(Args...,const sf::Event&);
        template<typename ...T>
        EventCallbackParamsEvent(FunctionType call,Args... args,const T ... t) : BaseEventCallable(t...), params(std::make_tuple(args ...)), callback(call) {};

        virtual void execute(const sf::Event& ev){apply(callback,ev,params);};

    private:
        FunctionType callback;
        std::tuple<Args...>& params;
};

#endif
