#ifndef EVENTCALLBACKPARAM_HPP
#define EVENTCALLBACKPARAM_HPP

#include "BaseEventCallable.hpp"

template<typename ... Args>
class EventCallbackParam : public BaseEventCallable
{
    public:
        typedef void (*FunctionType)(Args...);
        template<typename ...T>
        EventCallbackParam(FunctionType call,Args... args,const T ... t) : BaseEventCallable(t...), params(std::make_tuple(args ...)), callback(call) {};

        virtual void execute(const sf::Event& ev){apply(callback,params);};

    private:
        FunctionType callback;
        std::tuple<Args...> params;
};

#endif
