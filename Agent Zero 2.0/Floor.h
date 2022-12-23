#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;
using namespace sf;
class Floor
{
private:

	Sprite sprite;
	const bool damaging;

public:
	
	
	//Constructor Destructor
	Floor(sf::Texture& texture_sheet, sf::IntRect texture_rect, bool damaging = false);
	const FloatRect getGlobalBounds() const;

	void update();
	void render(RenderTarget& target);
};

