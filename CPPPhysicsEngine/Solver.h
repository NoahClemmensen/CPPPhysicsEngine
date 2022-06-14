#pragma once
#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include <iostream>

namespace sol {
    class Solver {
    public:
        sf::RenderWindow& Window;
        sfev::EventManager& EventManager;

        Solver(sf::RenderWindow& window, sfev::EventManager& evm) : Window(window), EventManager(evm) {}
        Solver() = delete;

        void Run() {
            Load();
            sf::Clock clock;
            while (Window.isOpen())
            {
                EventManager.processEvents();
                sf::Time elapsed = clock.restart();
                Update(elapsed.asSeconds());
                Render();
                Play();
            }
        }

        virtual void Update(float DeltaTime) {
            //std::cout << "Update: " << DeltaTime;
        }

        virtual void Load() {
            //std::cout << "Loaded";
        }

        virtual void Render() {
            //Window.clear(sf::Color::Blue);
            //Window.display();
        }

        virtual void Play() {

        }
    };
}