#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Game.h"
#include "Player.h"
#include "Floor.h"
#include "Map.h"

#include <iostream>

using namespace std;
using namespace sf;


int main()
{
	srand(static_cast<unsigned>(time(0)));

	Game game;
	Event event;

	//Game loop
	while(game.getWindow().isOpen())
	{
		
		game.update();
		game.render();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
