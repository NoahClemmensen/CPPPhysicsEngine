#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include "Solver.h"
#include <stdio.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Test");

    sfev::EventManager evm(window, true);
    evm.addEventCallback(sf::Event::EventType::Closed, [&](const sf::Event&) {window.close(); });
    evm.addKeyPressedCallback(sf::Keyboard::A, [&](const sf::Event&) {std::cout << "A Pressed" << std::endl; });
    evm.addKeyReleasedCallback(sf::Keyboard::A, [&](const sf::Event&) {std::cout << "A released" << std::endl; });

    evm.addMousePressedCallback(sf::Mouse::Button::Left, [&](const sf::Event&) {std::cout << "LEFT Mouse button pressed" << std::endl; });
    evm.addMouseReleasedCallback(sf::Mouse::Button::Left, [&](const sf::Event&) {std::cout << "LEFT Mouse button released" << std::endl; });

    evm.addMousePressedCallback(sf::Mouse::Button::Right, [&](const sf::Event&) {std::cout << "RIGHT Mouse button pressed" << std::endl; });
    evm.addMouseReleasedCallback(sf::Mouse::Button::Right, [&](const sf::Event&) {std::cout << "RIGHT Mouse button released" << std::endl; });

    sol::Solver solver(&evm, window);
    __raise evm.Load();

    while (window.isOpen())
    {
        evm.processEvents();
        __raise evm.Update(1.0f);
        __raise evm.Render();
        __raise evm.Play();
        

        window.clear();
        window.display();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
