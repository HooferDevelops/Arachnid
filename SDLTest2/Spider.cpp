#include "Spider.h"

#include <SDL_syswm.h>
#include <cmath>

Spider::Spider(SDL_Renderer* renderer) : current_sprite(renderer, "Assets/SpiderSheet.png") {
	current_sprite.SetSize(16, 16);
	current_sprite.SetPosition(250, 250);
	current_sprite.SetGridCount(4, 4);
	current_sprite.SetSpeed(200);

	spawn_time = SDL_GetTicks64();


	UpdateCurrent();
	UpdateTarget();

	offset_x = (rand() % 300) - 150;
	offset_y = (rand() % 300) - 150;


	current_sprite.SetPosition(starting_x, starting_y);
}

void Spider::UpdateCurrent() {
	int d_width = GetSystemMetrics(SM_CXSCREEN);
	int d_height = GetSystemMetrics(SM_CYSCREEN);

	bool top = (rand() % 2) == 1 ? true : false;
	bool inverse = (rand() % 2);

	if (top) {
		starting_x = rand() % d_width;
		starting_y = (d_height - 16) * inverse;
	}
	else {
		starting_x = (d_width - 16) * inverse;
		starting_y = rand() % d_height;
	}
}

void Spider::UpdateTarget() {
	int d_width = GetSystemMetrics(SM_CXSCREEN);
	int d_height = GetSystemMetrics(SM_CYSCREEN);

	bool top1 = (rand() % 2) == 1 ? true : false;
	bool inverse1 = (rand() % 2);

	if (top1) {
		target_x = rand() % d_width;
		target_y = (d_height - 16) * inverse1;
	}
	else {
		target_x = (d_width - 16) * inverse1;
		target_y = rand() % d_height;
	}

	walk_speed = 1 + (rand() % 60) / 10;
}

void Spider::Render() {
	current_sprite.Render();
}

void Spider::Logic() {
	int x = 0;
	int y = 0;

	SDL_GetGlobalMouseState(&x, &y);

	float lerp =  std::min((float)(SDL_GetTicks64() - spawn_time) / (5000 * walk_speed), 1.0f);

	float final_x = std::lerp(starting_x, target_x, lerp);
	float final_y = std::lerp(starting_y, target_y, lerp);

	current_sprite.SetPosition(final_x, final_y);

	if (lerp == 1) {
		starting_x = current_sprite.xPos;
		starting_y = current_sprite.yPos;
		
		spawn_time = SDL_GetTicks64();
		UpdateTarget();
	}
}