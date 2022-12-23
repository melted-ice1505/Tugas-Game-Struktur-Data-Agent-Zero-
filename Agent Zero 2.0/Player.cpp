#include "Player.h"


	//Animation

	//Movement

void Player::setPosition(const float x, const float y)
{
	this->pSprite.setPosition(x, y);
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::resetAnimTimer()
{
	this->animTimer.restart();
	this->animSwitch = true;
}
void Player::move(const float dirX, const float dirY)
{
	//Acceleration
	this->velocity.x += dirX * this->acc;
	this->velocity.y += dirY * this->acc;

	//Velocity Limiter
	if (abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f); //Compare if Player goes left(will output -1.f) or right(will output 1.f)
	}
	if (abs(this->velocity.y) > this->velocityMax)
	{
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}
}
void Player::updatePhys()
{
	//Gravity
	/*this->velocity.y += 1.0 * this->gravity;
	if (abs(this->velocity.y) > this->velocityMaxY)
		this->velocity.y = this->velocityMaxY;*/

	//Deceleration
	this->velocity *= this->drag; //V *= V*drag

	//Limit Deceleration
	if (abs(this->velocity.x) < this->velocityMin) //If V below min, Sprite stop
		this->velocity.x = 0.f;
	if (abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->pSprite.move(this->velocity);
}

//Private Functions
	void Player::initVariables()
	{
		this->animState = IDLE;
	}
	void Player::initTexture()
	{
		//Load Texture + Checker
		if (!this->pTexture.loadFromFile(PLAYER_SKIN))
		{
			cout << "Couldn't Load Texture File" << endl;
		}
	}
	void Player::initSprite()
	{
		//Set Texture
		this->pSprite.setTexture(this->pTexture);
		this->currentFrame = IntRect(224, 0, 32, 32);
		this->pSprite.setTextureRect(this->currentFrame);
		this->pSprite.setScale(2.f, 2.f);
	}
	void Player::initAnim()
	{
		this->animTimer.restart();
		this->animSwitch = true;
	}

	void Player::initPhys()
	{
		this->velocityMax = 7.f;
		this->velocityMin = 1.f;
		this->acc = 1.2f;
		this->drag = 0.87f;
		//this->gravity = 4.f;
		//this->velocityMaxY = 3.f;
	}

	//Contructor & Destructor
	Player::Player()
	{
		this->initVariables();
		this->initTexture();
		this->initSprite();
		this->initAnim();
		this->initPhys();
	}
	Player::~Player()
	{

	}

	const bool& Player::getAnimSwitch()
	{
		// TODO: insert return statement here
		bool anim_switch = this->animSwitch;

		if (this->animSwitch)
			this->animSwitch = false;

		return anim_switch;
	}
	const FloatRect Player::getGlobalBounds() const
	{

		return this->pSprite.getGlobalBounds();
	}

	void Player::updateMovement()
	{
		this->animState = IDLE;
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) //Move Left
		{
			this->move(-1.f, 0.f); //Sprite move left 1.f, vertical 0.f
			this->animState = MOVE_LEFT;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Key::Right)) //Move Right
		{
			this->move(1.f, 0.f); //Sprite move right 1.f, vertical 0.f
			this->animState = MOVE_RIGHT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) //Move Jump
		{
			this->move(0.f, -1.f);
			this->animState = JUMP;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) //Move Down
		{
			this->move(0.f, 1.f);
			this->animState = FALL;
		}
	}
	void Player::updateAnim()
	{
		if (this->animState == IDLE)
		{
			if (this->animTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
			{
				 //Idle Animation
				this->currentFrame.top = 0.f;
				this->currentFrame.left += 32.f;
				/*if (this->currentFrame.left >= 288.f)
					this->currentFrame.left = 192.f;*/
				if (this->currentFrame.left >= 256.f)
					this->currentFrame.left = 224.f;
				
				this->animTimer.restart();
				this->pSprite.setTextureRect(this->currentFrame);
			}
		}
		else if (this->animState == MOVE_LEFT)
		{
			if (this->animTimer.getElapsedTime().asSeconds() >= 0.2f)
			{
				//Move Left Animation
				this->currentFrame.top = 32.f;
				this->currentFrame.left += 32.f;
				if (this->currentFrame.left >= 288.f)
					this->currentFrame.left = 192.f;

				this->animTimer.restart();
				this->pSprite.setTextureRect(this->currentFrame);
			}
		}
		else if (this->animState == MOVE_RIGHT)
		{
			if (this->animTimer.getElapsedTime().asSeconds() >= 0.2f)
			{
				//Move Right Animation
				this->currentFrame.top = 64.f;
				this->currentFrame.left += 32.f;
				if (this->currentFrame.left >= 288.f)
					this->currentFrame.left = 192.f;

				this->animTimer.restart();
				this->pSprite.setTextureRect(this->currentFrame);
			}
		}
		else if (this->animState == JUMP)
		{
			if (this->animTimer.getElapsedTime().asSeconds() >= 0.2f)
			{
				//Move Right Animation
				this->currentFrame.top = 96.f;
				this->currentFrame.left += 32.f;
				if (this->currentFrame.left >= 288.f)
					this->currentFrame.left = 192.f;

				this->animTimer.restart();
				this->pSprite.setTextureRect(this->currentFrame);
			}
		}
		else if (this->animState == FALL)
		{
			if (this->animTimer.getElapsedTime().asSeconds() >= 0.2f)
			{
				//Move Right Animation
				this->currentFrame.top = 0.f;
				this->currentFrame.left += 32.f;
				if (this->currentFrame.left >= 288.f)
					this->currentFrame.left = 192.f;

				this->animTimer.restart();
				this->pSprite.setTextureRect(this->currentFrame);
			}
		}
	}

	//Functions
	void Player::update()
	{
		this->updateMovement();
		this->updateAnim();
		this->updatePhys();
	}
	void Player::render(RenderTarget& target)
	{
		target.draw(this->pSprite);
	}
