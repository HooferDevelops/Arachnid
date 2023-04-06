#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_syswm.h>

#include "SDLBase.h"

int main(int argc, char* args[])
{
	SDLBase Main = SDLBase();
	Main.CreateBaseWindow();

	Main.Preload();

	while (true) {
		if (SDL_GetTicks64() % 16 == 0) {
			Main.Logic();
			Main.Render();

			bool Shutdown = Main.Update();

			if (Shutdown) {
				break;
			}
		}
	}

	Main.Destroy();
	

	return 0;
}
