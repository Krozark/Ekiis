#ifndef EVENTCALLBACKHPP
#define EVENTCALLBACK_HPP

#include "BaseEventCallable.hpp"

template<typename ... Args>
class EventCallback : public BaseEventCallable
{
    public:
        typedef void (*FunctionType)(Args...);
        template<typename ...T>
        EventCallback(FunctionType call,Args... args,const T ... t) : BaseEventCallable(t...), params(std::make_tuple(args ...)), callback(call) {};

        virtual void execute(const sf::Event& ev){apply(callback,params);};

    private:
        FunctionType callback;
        std::tuple<Args...> params;
};

#endif
