#pragma once
#include "EventManager.h"
#include "SFML/Graphics.hpp"
#include <iostream>

namespace sol {
	class Solver
	{
	public:
		sf::RenderWindow &Window;

		Solver(sfev::EventManager* pSource, sf::RenderWindow& window) : Window(window) {
			__hook(&sfev::EventManager::Load, pSource, &Solver::Load);
			__hook(&sfev::EventManager::Update, pSource, &Solver::Update);
			__hook(&sfev::EventManager::Render, pSource, &Solver::Render);
			__hook(&sfev::EventManager::Play, pSource, &Solver::Play);
		}

		void Update(float DeltaTime) {
			std::cout << DeltaTime;
		}

		void Load() {
			std::cout << "Load";
		}

		void Render() {

		}

		void Play() {

		}
	};
}