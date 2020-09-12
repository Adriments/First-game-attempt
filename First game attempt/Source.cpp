//Include SDL headers
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Window* gameWindow = NULL;

	SDL_Surface* background = NULL;

	SDL_Renderer* gameRenderer = NULL;

	bool quit = false;

	SDL_Event e;

	SDL_Init(SDL_INIT_VIDEO);

	gameWindow = SDL_CreateWindow("Fire n' Forget", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);

	if(gameWindow == NULL) 
	{
		printf("Window failed to create: %s\n", SDL_GetError() );
		return 1;
	}

	if (gameRenderer == NULL)
	{
		printf("Renderer failed to start: %s\n", SDL_GetError() );
	}

	while (!quit)
	{
		while (SDL_PollEvent(&e) > 0)
		{
			if (e.type == SDL_QUIT)
			{
				printf("User Quit.");
				quit = true;
			}
		}

		//Clears the Renderer
		SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gameRenderer);

		//Draws a rectangle
		SDL_Rect rectangle1 = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
		SDL_SetRenderDrawColor(gameRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(gameRenderer, &rectangle1);

		//Puts rectangle on screen
		SDL_RenderPresent(gameRenderer);
	}

	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;
	gameRenderer = NULL;

	SDL_Quit();

	return 0;
}