//Include SDL headers
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Window* gameWindow = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	gameWindow = SDL_CreateWindow("Fire n' Forget", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(gameWindow == NULL) 
	{
		printf("Window failed to create: %s\n", SDL_GetError() );
		return 1;
	}

	SDL_Delay(3000);

	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	SDL_Quit();

	return 0;
}