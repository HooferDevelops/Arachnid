#include "SDLBase.h"

#include <iostream>

SDLBase::SDLBase() {
	printf("Initialized");
}

void SDLBase::CreateBaseWindow() {
	printf("Creating Window");

	desktopWidth = GetSystemMetrics(SM_CXSCREEN);
	desktopHeight = GetSystemMetrics(SM_CYSCREEN);

	window = SDL_CreateWindow("Arachnid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		desktopWidth, desktopHeight, SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SKIP_TASKBAR);


	// Add transparency fullscreen support
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(window, &wmInfo);
	HWND hWnd = wmInfo.info.win.window;
	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST | WS_EX_TOOLWINDOW);
	SetLayeredWindowAttributes(hWnd, RGB(255, 0, 255), 0, LWA_COLORKEY); 
	
	SDL_Surface* screenSurface = NULL;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void SDLBase::Preload() {
	AnimatedSprite spider = AnimatedSprite(renderer, "Assets/SpiderSheet.png");
	spider.SetSize(16, 16);
	spider.SetGridCount(4, 4);
	spider.SetPosition(125, 15);
	spider.SetSpeed(100);

	for (int i = 0; i < 1; i++) {
		Spider test = Spider(renderer);

		spiders.push_back(test);
	}

	sprites.push_back(spider);
}

void SDLBase::Render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderClear(renderer);

	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].Render();
	}

	for (int i = 0; i < spiders.size(); i++) {
		spiders[i].Render();
	}

	SDL_RenderPresent(renderer);
}

void SDLBase::Logic() {
	desktopWidth = GetSystemMetrics(SM_CXSCREEN);
	desktopHeight = GetSystemMetrics(SM_CYSCREEN);

	int x = 0;
	int y = 0;

	SDL_GetGlobalMouseState(&x, &y);

	SDL_SetWindowPosition(window, desktopWidth, desktopHeight / 2);

	for (int i = 0; i < spiders.size(); i++) {
		spiders[i].Logic();
	}
}

bool SDLBase::Update() {
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			return true;
		}
	}

	return false;
}

void SDLBase::Destroy() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}