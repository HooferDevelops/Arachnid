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
	Uint64 start_time;
	float walk_speed;

	int offset_x;
	int offset_y;
	bool moving_offset;
	Uint64 offset_start_time;
};