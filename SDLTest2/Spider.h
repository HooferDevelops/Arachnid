#pragma once
#include "AnimatedSprite.h"

class Spider 
{
public:
	Spider(SDL_Renderer* renderer);
	void Logic();
	void Render();
	void UpdateCurrent();
	void UpdateTarget();

private:
	AnimatedSprite current_sprite;
	int starting_x;
	int starting_y;
	int target_x;
	int target_y;
	int offset_x;
	int offset_y;
	Uint64 spawn_time;
	float walk_speed;
};