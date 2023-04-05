#pragma once

#include <SDL_image.h>

class AnimatedSprite
{
	public:
		AnimatedSprite(SDL_Renderer* renderer, const char* dir);
		void Render();
		void Logic();
		void SetSize(int x, int y);
		void SetPosition(int x, int y);
		void SetGridCount(int xC, int yC);
		void SetSpeed(int interval);
		void GetPosition(int *x, int *y);

	private:
		int speed;
		int xPos;
		int yPos;
		int xSize;
		int ySize;
		int xCount;
		SDL_Renderer* base_renderer;
		SDL_Surface *image;
		SDL_Texture *texture;
};
