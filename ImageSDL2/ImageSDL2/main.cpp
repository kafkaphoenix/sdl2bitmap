#include <SDL.h>

int main(int argc, char ** argv)
{
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("SDL Displaying Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Surface *image = SDL_LoadBMP("image.bmp");

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		SDL_Rect dstrect = { 50, 50, 320 ,240 };
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}