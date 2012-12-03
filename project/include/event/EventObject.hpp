#ifndef EVENTOBJECT_HPP
#define EVENTOBJECT_HPP

#include "BaseEventCallable.hpp"

template<typename C,typename ... Args>
class EventObject : public BaseEventCallable
{

    public:
        typedef void (C::*FunctionType)(Args ...);

        template <typename ... T>
        EventObject(C& obj,FunctionType methode,Args... args,const T ... t): BaseEventCallable(t ...), params(std::make_tuple(args ...)), obj (obj), callback (methode) {};

        virtual void execute(const sf::Event& ev){apply(obj,callback,params);};

    private:
        C& obj;
        FunctionType callback;
        std::tuple<Args...> params;
};


#endif
