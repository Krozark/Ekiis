#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <SFML/Graphics.hpp>
#include "../Event/src/Event/BaseEventCallable.hpp"

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(const sf::VideoMode mode, const std::string &title,const unsigned int max_fps=60);
        ~MainWindow();

        inline void addEvent(BaseEventCallable* ev,bool hold=false)
        {
            if (hold && (ev->event.type == sf::Event::KeyPressed || ev->event.type == sf::Event::MouseButtonPressed || ev->event.type == sf::Event::JoystickButtonPressed))
                events.push_back(ev);
            else
                momentEvents.emplace_back(ev);
        };

        void addCloseEvent();
        void resizeSlot(const sf::Event& ev);
        void moveView(float x,float y);
        void doEvents();

    private:
        std::vector<BaseEventCallable*> momentEvents;
        std::vector<BaseEventCallable*> events;
        sf::Clock LoopClock;
        int elapsedTime;
};

#endif
