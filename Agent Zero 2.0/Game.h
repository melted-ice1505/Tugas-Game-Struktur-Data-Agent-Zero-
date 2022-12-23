#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include <iostream>

#define BACKGROUND "Graphics/BG/GameBG.png"


using namespace std;
using namespace sf;

class Game
{
private:

	Sprite BG;
	Texture BG_Texture;

	//Windows
	RenderWindow window;
	Event ev;

	//Objects
	Player* player;

	//Private Functions
	void initWindow();
	void initBG();
	void initBGText();
	void initBGSprite();
	void initPlayer();

public:
	//Contructor & Destructor
	Game();
	virtual ~Game();



		//Functions

		void updatePlayer();
		void updateCollision();
		void update();
		void renderBG();
		void renderPlayer();
		void render();
		const RenderWindow& getWindow() const;
};

