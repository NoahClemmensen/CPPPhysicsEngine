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
    
    sol::Solver* solver = new Solver(window, evm);
    solver->Run();
}

class Solver : public sol::Solver {
public:
    sf::RenderWindow& Window;
    sfev::EventManager& EventManager;

    Solver(sf::RenderWindow& window, sfev::EventManager& evm) : Window(window), EventManager(evm) {}

    virtual void Update(float DeltaTime) {
        std::cout << "Update " << DeltaTime;
    }

    virtual void Load() {

    }

    virtual void Render() {
        Window.clear(sf::Color::Blue);
        Window.display();
    }

    virtual void Play() {

    }
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
