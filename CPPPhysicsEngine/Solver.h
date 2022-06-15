#pragma once
#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include <iostream>
#include "Container.h"
#include "Geometry.h"

namespace sol {
    class Solver {
    public:
        sf::RenderWindow& Window;
        sfev::EventManager& EventManager;
        con::Container& Container;

        Solver(sf::RenderWindow& window, sfev::EventManager& eventManager, con::Container& container) : Window(window), EventManager(eventManager), Container(container) {}
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

        virtual void Update(float DeltaTime) = 0;
        virtual void Load() = 0;
        virtual void Render() = 0;
        virtual void Play() = 0;
    };
}