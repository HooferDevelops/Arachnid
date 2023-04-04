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
}

void SDLBase::Preload() {
	AnimatedSprite spider = AnimatedSprite(renderer, "Assets/SpiderSheet.png");
	spider.SetSize(16, 16);
	spider.SetGridCount(4, 4);
	spider.SetPosition(125, 15);

	sprites.push_back(spider);
}

void SDLBase::Render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

	SDL_RenderClear(renderer);

	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].Render();
	}

/*	SDL_Texture* img = NULL;
	int w, h;
	img = IMG_LoadTexture(renderer, "Assets/SpiderSheet.png");
	SDL_QueryTexture(img, NULL, NULL, &w, &h);
	SDL_Rect textr;
	textr.x = 0;
	textr.y = 0;
	textr.w = w * 2;
	textr.h = h * 2;

	SDL_RenderCopy(renderer, img, NULL, &textr);
*/

	SDL_RenderPresent(renderer);
	//SDL_DestroyTexture(img);
}

void SDLBase::Logic() {
	desktopWidth = GetSystemMetrics(SM_CXSCREEN);
	desktopHeight = GetSystemMetrics(SM_CYSCREEN);
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