#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Log.h"

class Game{
public:
	Game();
	~Game();
	void gameLoop();
private:
	void gameRender();
	void gameInput();
	bool gameInitialize();

	bool loadMedia();

	Log logger;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Surface* background;

	SDL_Event e;

	bool running;
};