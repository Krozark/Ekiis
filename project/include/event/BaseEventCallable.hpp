#ifndef BASEEVENTCALLABLE_HPP
#define BASEEVENTCALLABLE_HPP

#include <SFML/Window/Event.hpp>

#define GCC_VERSION (__GNUC__ * 10000 \
                   + __GNUC_MINOR__ * 100 \
                   + __GNUC_PATCHLEVEL__)

#if GCC_VERSION < 40700

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

template<class Ret, class... Args, int... Indexes,typename ...T >
Ret apply_helper( Ret (*pf)(Args...),T... t, index_tuple< Indexes... >, tuple<Args...>&& tup)
{
    return pf(t...,forward<Args>( get<Indexes>(tup))...);
}

template<class Ret, class ... Args,typename ...T>
Ret apply(Ret (*pf)(Args...),T...t, const tuple<Args...>&  tup)
{
    return apply_helper(pf, t...,typename make_indexes<Args...>::type(), tuple<Args...>(tup));
}

template<class Ret, class ... Args,typename ...T>
Ret apply(Ret (*pf)(Args...),T...t, tuple<Args...>&&  tup)
{
    return apply_helper(pf,t..., typename make_indexes<Args...>::type(), forward<tuple<Args...>>(tup));
}

#else


#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>

template<size_t N>
struct Apply {
    template<typename F, typename T, typename... A>
    static inline auto apply(F&& f, T && t, A &&... a)
        -> decltype(Apply<N-1>::apply(::std::forward<F>(f), ::std::forward<T>(t),
            ::std::get<N-1>(::std::forward<T>(t)), ::std::forward<A>(a)...
        ))
    {
        return Apply<N-1>::apply(::std::forward<F>(f), ::std::forward<T>(t),
            ::std::get<N-1>(::std::forward<T>(t)), ::std::forward<A>(a)...
        );
    }
};

template<>
struct Apply<0> {
    template<typename F, typename T, typename... A>
    static inline auto apply(F && f, T &&, A &&... a)
        -> decltype(f(::std::forward<A>(a)...))
    {
        return f(::std::forward<A>(a)...);
    }
};

template<typename F, typename T>
inline auto apply(F && f, T && t)
     -> decltype(Apply< ::std::tuple_size<
         typename ::std::decay<T>::type
     >::value>::apply(::std::forward<F>(f), ::std::forward<T>(t)))
{
    return Apply< ::std::tuple_size<
        typename ::std::decay<T>::type
    >::value>::apply(f, ::std::forward<T>(t));
}
#endif

class MainWindow;

class BaseEventCallable
{
    public:
        BaseEventCallable(const sf::Event& ev);
        BaseEventCallable(const sf::Event::EventType &evtType);
        BaseEventCallable(const sf::Event::EventType &evtType,const sf::Mouse::Button button);
        BaseEventCallable(const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt, bool ctlr, bool shift, bool system);
        BaseEventCallable(const sf::Event::EventType &evtType,const int joyId, const int button);

        virtual void execute(const sf::Event& event) = 0;

        bool operator == (const sf::Event& other)const;

    protected:
        friend class MainWindow;
        sf::Event event;
};

#endif
