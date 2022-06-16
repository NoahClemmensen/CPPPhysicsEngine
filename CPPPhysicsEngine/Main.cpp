#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include <stdio.h>
#include "Solver.h"
#include "Container.h"
#include "Geometry.h"
#include "Math.h"

class SolverChild : public sol::Solver {
public:

    sf::Vector2f Gravity = { 0.0f, 0.982f };

    SolverChild(sf::RenderWindow& window, sfev::EventManager& eventManager, con::Container container, size_t subSteps) : sol::Solver(window, eventManager, container, subSteps) {}

    virtual void Load() {
        EventManager.addEventCallback(sf::Event::EventType::Closed, [&](const sf::Event&) {
            Window.close();
            });

        geo::Circle* circle = new geo::Circle(50.0f, Window.getView().getCenter() + sf::Vector2f{ 0.0f, -90.0f }, sf::Color::Red, 50);
        geo::Circle* circle2 = new geo::Circle(50.0f, Window.getView().getCenter() + sf::Vector2f{ -200.0f, 0.0f }, sf::Color::Blue, 50);

        geo::CircleConstraint* constraint = new geo::CircleConstraint(350.0f, Window.getView().getCenter(), sf::Color::Black, 50);

        Container.Add(circle);
        Container.Add(circle2);
        Container.Add(constraint);

        std::cout << "Loaded";
    }

    virtual void Update() {
        
        ApplyGravity();

        for (int i = 0; i < SubSteps; i++) {
            SolveConstraint();
            SolveCollisions();
        }

        UpdatePositions();
        UpdateOpacity();
    }

    virtual void Render() {
        Window.clear(sf::Color::White);

        for (int i = 0; i < Container.CircleConstraints.size(); i++) {
            Window.draw(*Container.CircleConstraints[i]);
        }

        for (int i = 0; i < Container.Circles.size(); i++) {
            Window.draw(*Container.Circles[i]);
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

    void UpdatePositions() {
        for (int i = 0; i < Container.Circles.size(); i++) {
            Container.Circles[i]->UpdatePosition(DeltaTime);
        }
    }

    void UpdateOpacity() {
        int opacity = sin(TotalElapsedTime.asSeconds());
        for (int i = 0; i < Container.Circles.size(); i++) {
            Container.Circles[i]->Color.a = opacity;
        }
    }

    void SolveConstraint() {
        for (int i = 0; i < Container.Circles.size(); i++) {
            geo::Circle* circle = Container.Circles[i];
            for (int k = 0; k < Container.CircleConstraints.size(); k++) {
                geo::CircleConstraint* constraint = Container.CircleConstraints[k];

                sf::Vector2f toObj = circle->Position - constraint->Position;
                float distance = MathVec2f::length(toObj);

                if (distance + circle->Radius > constraint->Radius) {
                    sf::Vector2f n = MathVec2f::setLength(toObj, constraint->Radius) - MathVec2f::setLength(toObj, circle->Radius + distance);
                    sf::Vector2f m = circle->Position + n;
                    circle->SetPositionVec2f(m);
                }
            }
        }
    }

    void SolveCollisions() {
        for (int i = 0; i < Container.Circles.size(); i++) {
            geo::Circle* cir1 = Container.Circles[i];
            for (int k = i+1; k < Container.Circles.size(); k++) {
                geo::Circle* cir2 = Container.Circles[k];

                sf::Vector2f collision = cir1->Position - cir2->Position;
                float distance = MathVec2f::length(collision);

                if (distance < cir1->Radius + cir2->Radius) {
                    sf::Vector2f n = collision / distance;
                    float delta = cir1->Radius + cir2->Radius - distance;
                    cir1->SetPositionVec2f(cir1->Position += 0.5f * delta * n);
                    cir2->SetPositionVec2f(cir2->Position -= 0.5f * delta * n);
                }
            }
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Test");
    sfev::EventManager evm(window, true);
    evm.addEventCallback(sf::Event::EventType::Closed, [&](const sf::Event&) {window.close(); });
    con::Container container;
    
    size_t subSteps = 2;

    sol::Solver* solver = new SolverChild(window, evm, container, subSteps);
    solver->Run();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
