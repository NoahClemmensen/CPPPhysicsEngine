#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include <stdio.h>
#include "Solver.h"
#include "Container.h"
#include "Geometry.h"

class SolverChild : public sol::Solver {
public:

    sf::Vector2f Gravity = { 0.0f, 9.82f };

    SolverChild(sf::RenderWindow& window, sfev::EventManager& eventManager, con::Container container) : sol::Solver(window, eventManager, container) {}

    virtual void Load() {
        EventManager.addEventCallback(sf::Event::EventType::Closed, [&](const sf::Event&) {
            Window.close();
            });

        geo::Circle circle(20.0f, { 200.0f, 200.0f }, sf::Color::White, 50);
        Container.Add(&circle);

        std::cout << "Loaded";
    }

    virtual void Update(float DeltaTime) {
        ApplyGravity();
        UpdatePositions(DeltaTime);
    }

    virtual void Render() {
        Window.clear(sf::Color::Black);

        for (int i = 0; i < Container.Drawables.size(); i++) {
            Window.draw(*Container.Drawables[i]);
        }

        Window.display();
    }

    virtual void Play() {

    }

    void ApplyGravity() {
        for (int i = 0; i < Container.Circles.size(); i++) {
            Container.Circles[i]->Accelerate(Gravity);
        }
    }

    void UpdatePositions(float DeltaTime) {
        for (int i = 0; i < Container.Circles.size(); i++) {
            Container.Circles[i]->UpdatePosition(DeltaTime);
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Test");
    sfev::EventManager evm(window, true);
    evm.addEventCallback(sf::Event::EventType::Closed, [&](const sf::Event&) {window.close(); });
    con::Container container;
    
    sol::Solver* solver = new SolverChild(window, evm, container);
    solver->Run();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
