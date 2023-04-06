#pragma once

#include <SDL_image.h>

class AnimatedSprite
{
	public:
		AnimatedSprite(SDL_Renderer* renderer, const char* dir);
		void Render();
		void Logic();
		void SetSize(int x, int y);
		void SetPosition(float x, float y);
		void SetGridCount(int xC, int yC);
		void SetSpeed(int interval);
		float xPos;
		float yPos;

	private:
		int speed;
		int xSize;
		int ySize;
		int xCount;
		SDL_Renderer* base_renderer;
		SDL_Surface *image;
		SDL_Texture *texture;
};
