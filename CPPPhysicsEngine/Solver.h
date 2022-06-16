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
        sf::Time TotalElapsedTime;
        float DeltaTime = 0.0f;
        size_t SubSteps = 1;

        Solver(sf::RenderWindow& window, sfev::EventManager& eventManager, con::Container& container, size_t subSteps) : Window(window), EventManager(eventManager), Container(container), SubSteps(subSteps) {}
        Solver() = delete;

        void Run() {
            Load();
            sf::Clock clock;
            while (Window.isOpen())
            {
                EventManager.processEvents();
                sf::Time elapsed = clock.restart();
                TotalElapsedTime += elapsed;
                DeltaTime = elapsed.asSeconds();
                Update();
                Render();
                Play();
            }
        }

        virtual void Update() = 0;
        virtual void Load() = 0;
        virtual void Render() = 0;
        virtual void Play() = 0;
    };
}