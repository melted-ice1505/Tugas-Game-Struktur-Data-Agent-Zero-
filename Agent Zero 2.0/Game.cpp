#include "Game.h"
#include "Player.h"
#include "Floor.h"
#include "Map.h"

	
	//Private Functions
	void Game::initWindow()
	{
		this->window.create(VideoMode(1280, 720), "Agent Zero", Style::Titlebar | Style::Close);
		this->window.setFramerateLimit(60);
	}
	void Game::initBG()
	{
		if (!this->BG_Texture.loadFromFile(BACKGROUND))
		{
			cout << "Couldn't Load BG Texture File" << endl;
		}
		this->BG.setTexture(this->BG_Texture);
	}
	void Game::initPlayer()
	{
		this->player = new Player(); //Assign new Player
	}

	//Contructor & Destructor
	Game::Game()
	{
		this->initWindow();
		this->initBG();
		this->initPlayer();

	}
	Game::~Game()
	{
		delete this->player;
	}


	//Functions
	const RenderWindow& Game::getWindow() const
	{
		return this->window;
	}
	
	void Game::updatePlayer()
	{
		this->player->update();
	}
	void Game::updateCollision()
	{
		//Collision with the bottom of screen
		if (this->player->getGlobalBounds().top + this->player->getGlobalBounds().height > this->window.getSize().y)
		{
			this->player->resetVelocityY();
			this->player->setPosition(this->player->getGlobalBounds().left, this->window.getSize().y - this->player->getGlobalBounds().height);
		}
	}
	void Game::update()
	{
		//Poll Event
		while (this->window.pollEvent(this->ev))
		{
			if (this->ev.type == Event::Closed)
				this->window.close();
			else if (this->ev.type == Event::KeyPressed && this->ev.key.code == Keyboard::Escape)
				this->window.close();

			if (this->ev.type == Event::KeyReleased && 
				(this->ev.key.code == Keyboard::Left || 
				this->ev.key.code == Keyboard::Right || 
				this->ev.key.code == Keyboard::Up || 
				(this->ev.key.code == Keyboard::Down)
					)
				)
				this->player->resetAnimTimer();
		}

		//Update Player
		this->updatePlayer();

		this->updateCollision();
	}
	void Game::renderPlayer()
	{
		this->player->render(this->window);
	}
	void Game::render()
	{
		this->window.clear();

		//Render
		this->window.draw(BG);
		this->renderPlayer();

		this->window.display();
	}