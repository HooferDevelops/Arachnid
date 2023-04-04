
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

void AnimatedSprite::Render() {
	SDL_Rect sizeRect = {
		0,
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