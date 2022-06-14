#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include <stdio.h>
#include "Solver.h"

class SolverChild : public sol::Solver {
public:

    SolverChild(sf::RenderWindow& window, sfev::EventManager& evm) : sol::Solver(window, evm) {}

    virtual void Load() {
        EventManager.addEventCallback(sf::Event::EventType::Closed, [&](const sf::Event&) {
            Window.close();
            });
        std::cout << "Loaded";
    }

    virtual void Update(float DeltaTime) {
        std::cout << " Update: " << DeltaTime;
    }

    virtual void Render() {
        Window.clear(sf::Color::Blue);
        Window.display();
    }

    virtual void Play() {

    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Test");
    sfev::EventManager evm(window, true);
    evm.addEventCallback(sf::Event::EventType::Closed, [&](const sf::Event&) {window.close(); });
    
    sol::Solver* solver = new SolverChild(window, evm);
    solver->Run();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
