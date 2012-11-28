#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <SFML/Graphics.hpp>
#include "event/BaseEventCallable.hpp"

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(const sf::VideoMode mode, const std::string &title,const unsigned int max_fps=60);
        ~MainWindow();

        inline void addEvent(BaseEventCallable* ev){events.push_back(ev);};

        void addCloseEvent();
        void doEvents();

    private:
        std::vector<BaseEventCallable*> events;
};

#endif
