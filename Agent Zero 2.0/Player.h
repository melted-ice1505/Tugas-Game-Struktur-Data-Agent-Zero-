#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define PLAYER_SKIN "Graphics/Characters/Actor5.png"

using namespace std;
using namespace sf;

enum P_ANIM_STATE {IDLE = 0, MOVE_LEFT, MOVE_RIGHT, JUMP, FALL};
class Player
{
private:
	Sprite pSprite;
	Texture pTexture;
	Clock animTimer;

	//Animation
	short animState;
	IntRect currentFrame;
	bool animSwitch;

	//Physics
	Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acc;	//Acceleration
	float drag;	//Decrease speed
	float gravity;
	float velocityMaxY; //Max V for Gravity

	//Private Functions
	void initTexture();
	void initSprite();
	void initAnim();
	void initPhys();

public:
	//Contructor & Destructor
	Player();
	virtual ~Player();

	//Accessor
	const bool& getAnimSwitch();
	const FloatRect getGlobalBounds() const;

	//Modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();

	//Functions
	void initVariables();

	void resetAnimTimer();
	void move(const float dirX, const float dirY);
	void updatePhys();
	void updateMovement();
	void updateAnim();
	void update();
	void render(RenderTarget& target);

};

