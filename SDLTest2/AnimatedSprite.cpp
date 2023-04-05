
#include "AnimatedSprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite(SDL_Renderer* renderer, const char* dir) {
	base_renderer = renderer;

	image = IMG_Load(dir);
	texture = SDL_CreateTextureFromSurface(renderer, image);
}

void AnimatedSprite::SetSize(int x, int y) {
	xSize = x;
	ySize = y;
}

void AnimatedSprite::SetGridCount(int xC, int yC) {
	xCount = xC;
}

void AnimatedSprite::SetPosition(int x, int y) {
	xPos = x;
	yPos = y;
}

void AnimatedSprite::SetSpeed(int interval) {
	speed = interval;
}

void AnimatedSprite::GetPosition(int* x, int* y)
{
	x = (int*) xPos;
	y = (int*) yPos;
}

void AnimatedSprite::Render() {
	int ticks = SDL_GetTicks64() / speed;

	SDL_Rect sizeRect = {
		(ticks % xCount) * xSize,
		0,
		xSize,
		ySize
	};

	SDL_Rect posRect = {
		xPos,
		yPos,
		xSize,
		ySize
	};

	SDL_RenderCopy(base_renderer, texture, &sizeRect, &posRect);
}

void AnimatedSprite::Logic() {

}