#include "Game.h"
#include <iostream>

SDL_Rect dst;
void Game::init(bool fs)
{
	int flags = 0;
	if (fs)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL up and running" << std::endl;
		window = SDL_CreateWindow(WIN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, flags);
		if (window)
		{
			 std::cout << "Window up and running" << std::endl;
			//Logger::getError(std::cout, "Creating window");

		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer up and running" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;

	}
		






}

void Game::update()
{
	 counter++;
	 std::cout << counter << std::endl;

	dst.w = 32;
	dst.h = 32;
	dst.x = counter;
}

void Game::handleEvents()
{

	SDL_Event ev;

	SDL_PollEvent(&ev);

	switch (ev.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}

}

void Game::render()
{
	SDL_Texture *tex = nullptr;
	SDL_RenderClear(renderer);
	// Render logic starts
	tex = IMG_LoadTexture(renderer, "./assets/playerO.png");
	if (tex == NULL) {
		std::cout << SDL_GetError() << std::endl;
	}




	SDL_RenderCopy(renderer, tex, NULL, &dst);
	

	// Render logic ends
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}


