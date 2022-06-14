#pragma once
#include "EventManager.h"
#include "SFML/Graphics.hpp"
#include <iostream>

namespace sol {
	class Solver
	{
	public:
		sf::RenderWindow& Window;
		sfev::EventManager& EventManager;

		Solver(sf::RenderWindow& window, sfev::EventManager& evm) : Window(window), EventManager(evm) {}

		void Run() {
			Load();
			while (Window.isOpen())
			{
				EventManager.processEvents();
				Update(1.0);
				Render();
				Play();
			}
		}

	private:
		virtual void Update(float DeltaTime) = 0;
		virtual void Load() = 0;
		virtual void Render() = 0;
		virtual void Play() = 0;
	};
}