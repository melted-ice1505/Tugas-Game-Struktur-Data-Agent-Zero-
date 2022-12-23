#include "Floor.h"

Floor::Floor(Texture& texture_sheet, IntRect texture_rect, bool damaging) : damaging(damaging)
{
	this->sprite.setTexture(texture_sheet);
	this->sprite.setTextureRect(texture_rect);
}


const FloatRect Floor::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
	
}



void Floor::update()
{

}

void Floor::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
