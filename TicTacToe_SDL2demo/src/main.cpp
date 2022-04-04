#include "Game.h"
Game* app = nullptr;
int main(int argc, char *argv[]) {
	
	app = new Game();
	app->init(false);
	
	while (app->running()) {
		Uint64 startT = SDL_GetPerformanceCounter();

		app->handleEvents();
		app->update();
		app->render();

		Uint64 endT = SDL_GetPerformanceCounter();

		float elapsedMS = (endT - startT) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

		// Cap to 60 FPS
		SDL_Delay(floor(16.666f - elapsedMS));
	}
		
	app->clean();


	return 0;
}