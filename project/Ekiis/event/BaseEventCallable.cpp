#include "BaseEventCallable.hpp"

#include <iostream>
using namespace std;

BaseEventCallable::BaseEventCallable(const sf::Event& ev)
{
    event = ev;
};

BaseEventCallable::BaseEventCallable(const sf::Event::EventType &evtType)
{
    event.type = evtType;
};

BaseEventCallable::BaseEventCallable(const sf::Event::EventType &evtType,const sf::Mouse::Button button)
{
    event.type = evtType;
    event.mouseButton.button = button;
};

BaseEventCallable::BaseEventCallable(const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt, bool ctlr, bool shift, bool system)
{
    event.type = evtType;
    event.key.code = code;
    event.key.alt = alt;
    event.key.control = ctlr;
    event.key.shift = shift;
    event.key.system = system;
};

BaseEventCallable::BaseEventCallable(const sf::Event::EventType &evtType,const int joyId, const int button)
{
    event.type = evtType;
    event.joystickButton.joystickId = joyId;
    event.joystickButton.button = button;
};

bool BaseEventCallable::operator == (const sf::Event& other)const
{
     if (event.type == other.type)
    {
        if(event.type == sf::Event::Closed
           || event.type == sf::Event::Resized
           || event.type == sf::Event::LostFocus
           || event.type == sf::Event::GainedFocus
           || event.type == sf::Event::TextEntered
           || event.type == sf::Event::MouseWheelMoved
           || event.type == sf::Event::MouseMoved
           || event.type == sf::Event::MouseEntered
           || event.type == sf::Event::MouseLeft
           || event.type == sf::Event::JoystickMoved
           || event.type == sf::Event::JoystickConnected
           || event.type == sf::Event::JoystickDisconnected)
            return true;
        // Si l'évènement est un bouton du clavier
        if (((event.type == sf::Event::KeyPressed) || (event.type == sf::Event::KeyReleased))
            && (event.key.code == other.key.code)
            && (event.key.alt == other.key.alt)
            && (event.key.control == other.key.control)
            && (event.key.shift == other.key.shift)
            && (event.key.system == other.key.system))
                return true;

        if ((event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
            && event.mouseButton.button == other.mouseButton.button)
            return true;

        if ((event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased)
            && (event.joystickButton.joystickId == other.joystickButton.joystickId)
            && (event.joystickButton.button == other.joystickButton.button))
            return true;


    }
    return false;
};

bool BaseEventCallable::test()
{
    if (event.type == sf::Event::KeyPressed)
        return sf::Keyboard::isKeyPressed(event.key.code);

    if (event.type == sf::Event::MouseButtonPressed)
        return sf::Mouse::isButtonPressed(event.mouseButton.button);

    if (event.type == sf::Event::JoystickButtonPressed)
        return sf::Joystick::isButtonPressed(event.joystickButton.joystickId,event.joystickButton.button);

    return false;
};

