#pragma once
#include "AnimatedSprite.h"

class Spider 
{
public:
	Spider(SDL_Renderer* renderer);
	void Logic();
	void Render();

private:
	AnimatedSprite current_sprite;
};