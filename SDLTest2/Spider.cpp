#include "Spider.h"

#include <cmath>

Spider::Spider(SDL_Renderer* renderer) : current_sprite(renderer, "Assets/TestSheet.png") {
	current_sprite.SetSize(16, 16);
	current_sprite.SetPosition(250, 250);
	current_sprite.SetGridCount(4, 4);
	current_sprite.SetSpeed(10);
}

void Spider::Render() {
	current_sprite.Render();
}

void Spider::Logic() {
	int x = 0;
	int y = 0;

	SDL_GetGlobalMouseState(&x, &y);

	int cX = 0;
	int cY = 0;

	current_sprite.GetPosition(&cX, &cY);

	current_sprite.SetPosition(x, y);
}