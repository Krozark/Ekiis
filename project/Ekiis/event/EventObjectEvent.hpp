#ifndef EVENTOBJECTEVENT_HPP
#define EVENTOBJECTEVENT_HPP

#include "BaseEventCallable.hpp"

template<typename C,typename ... Args>
class EventObjectEvent : public BaseEventCallable
{
    public:
        typedef void (C::*FunctionType)(const sf::Event&,Args...);
        template<typename ...T>
        EventObjectEvent(C& obj,FunctionType methode,Args... args,const T ... t): BaseEventCallable(t ...), params(std::make_tuple(args ...)), obj (obj), callback (methode) {};

        virtual void execute(const sf::Event& ev){apply(obj,callback,ev,params);};

    private:
        C& obj;
        FunctionType callback;
        std::tuple<Args...> params;
};


#endif
