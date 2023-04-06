#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_syswm.h>
#include <vector>

#include "AnimatedSprite.h"
#include "Spider.h"

class SDLBase
{
public:
	SDLBase();
	void CreateBaseWindow();
	void Preload();
	void Render();
	void Logic();
	bool Update();
	void Destroy();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int desktopWidth;
	int desktopHeight;
	std::vector<AnimatedSprite> sprites;
	std::vector<Spider> spiders;
};

