#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Logger.h"
#include "defs.h"

class Game
{
public:
	void init(bool fs);

	void update();
	void handleEvents();


	void render();

	bool running() { return isRunning; };
	void clean();
private:
	int counter = 0;
	bool isRunning = false;
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;


};

