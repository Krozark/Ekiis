#ifndef BASEEVENTCALLABLE_HPP
#define BASEEVENTCALLABLE_HPP

#include <SFML/Window/Event.hpp>

// ------------- UTILITY---------------
template<int...> struct index_tuple{};

template<int I, typename IndexTuple, typename... Types>
struct make_indexes_impl;

template<int I, int... Indexes, typename T, typename ... Types>
struct make_indexes_impl<I, index_tuple<Indexes...>, T, Types...>
{
    typedef typename make_indexes_impl<I + 1, index_tuple<Indexes..., I>, Types...>::type type;
};

template<int I, int... Indexes>
struct make_indexes_impl<I, index_tuple<Indexes...> >
{
    typedef index_tuple<Indexes...> type;
};

template<typename ... Types>
struct make_indexes : make_indexes_impl<0, index_tuple<>, Types...>
{};

 // ----------UNPACK TUPLE AND APPLY TO FUNCTION ---------
#include <tuple>
#include <iostream>

using namespace std;

template<class Ret, class... Args, int... Indexes>
Ret apply_helper( Ret (*pf)(const sf::Event&,Args...),const sf::Event& ev, index_tuple< Indexes... >, tuple<Args...>&& tup)
{
    return pf(ev,forward<Args>( get<Indexes>(tup))...);
};

template<class Ret, class... Args, int... Indexes>
Ret apply_helper( Ret (*pf)(Args...), index_tuple< Indexes... >, tuple<Args...>&& tup)
{
    return pf(forward<Args>( get<Indexes>(tup))...);
};

template<typename Ret,typename ... Args>
Ret apply(Ret (*pf)(const sf::Event&,Args...),const sf::Event& ev, const tuple<Args...>&  tup)
{
    return apply_helper(pf,ev,typename make_indexes<Args...>::type(), tuple<Args...>(tup));
};

template<typename Ret,typename ... Args>
Ret apply(Ret (*pf)(Args...), const tuple<Args...>&  tup)
{
    return apply_helper(pf,typename make_indexes<Args...>::type(), tuple<Args...>(tup));
};


/************* obj::methode ****************************/


template<class Ret,typename T, class... Args, int... Indexes>
Ret apply_helper(T& t, Ret (T::*pf)(const sf::Event&,Args...),const sf::Event& ev, index_tuple< Indexes... >, tuple<Args...>&& tup)
{
    return (t.*pf)(ev,forward<Args>( get<Indexes>(tup))...);
};

template<class Ret,typename T, class... Args, int... Indexes>
Ret apply_helper(T& t, Ret (T::*pf)(Args...), index_tuple< Indexes... >, tuple<Args...>&& tup)
{
    return (t.*pf)(forward<Args>( get<Indexes>(tup))...);
};

template<typename Ret,typename T,typename ... Args>
Ret apply(T& t,Ret (T::*pf)(const sf::Event&,Args...),const sf::Event& ev, const tuple<Args...>&  tup)
{
    return apply_helper(t,pf,ev,typename make_indexes<Args...>::type(), tuple<Args...>(tup));
};

template<typename Ret,typename T,typename ... Args>
Ret apply(T& t,Ret (T::*pf)(Args...), const tuple<Args...>&  tup)
{
    return apply_helper(t,pf,typename make_indexes<Args...>::type(), tuple<Args...>(tup));
};



/*
template<class Ret, class ... Args>
Ret apply(Ret (*pf)(Args...), tuple<Args...>&&  tup)
{
    return apply_helper(pf, typename make_indexes<Args...>::type(), forward<tuple<Args...>>(tup));
}
*/

class MainWindow;

class BaseEventCallable
{
    public:
        BaseEventCallable(const sf::Event& ev);
        BaseEventCallable(const sf::Event::EventType &evtType);
        BaseEventCallable(const sf::Event::EventType &evtType,const sf::Mouse::Button button);
        BaseEventCallable(const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr=false, bool shift=false, bool system=false);
        BaseEventCallable(const sf::Event::EventType &evtType,const int joyId, const int button);

        virtual void execute(const sf::Event& event) = 0;

        bool operator == (const sf::Event& other)const;
        bool test();

    protected:
        friend class MainWindow;
        sf::Event event;

};

#endif
