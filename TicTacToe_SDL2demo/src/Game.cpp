#include "Game.h"
#include <iostream>
#include "TextureManager.h"


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
		_TextureManager::Instance()->load("playerX", "assets/playerX.png", renderer);
		_TextureManager::Instance()->load("playerO", "assets/playerO.png", renderer);
		_TextureManager::Instance()->load("tileSet1", "assets/bgSetOne.png", renderer);

	}
	else
	{
		isRunning = false;

	}
		






}

void Game::update()
{
	 // counter++;
	 // std::cout << counter << std::endl;


}

void Game::handleEvents()
{

	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type)
		{
		case SDL_QUIT:
		
			isRunning = false;
			break;
		


		default:
			break;
		}
	}

	

}

void Game::render()
{
	
	SDL_RenderClear(renderer);
	// Render logic starts
	_TextureManager::Instance()->genBoard(renderer);

	// Render logic ends
	SDL_RenderPresent(renderer);
}

void Game::clean()
{	
	_TextureManager::Instance()->clean();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}


