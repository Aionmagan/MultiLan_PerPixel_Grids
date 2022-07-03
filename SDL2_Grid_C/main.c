#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCRN_W 640
#define SCRN_H 480

SDL_Window *window; 
SDL_Surface *screen; 

void init()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Grid", SDL_WINDOWPOS_CENTERED,
			                  		  SDL_WINDOWPOS_CENTERED,                                          
			                  		  SCRN_W, SCRN_H, 
					  		  		  SDL_WINDOW_OPENGL);
	screen = SDL_GetWindowSurface(window);
}

void draw_grid(uint32_t *pixels, int width, int grid_size)
{
	int x, y, w, g;
    int result = 0; 	
	int bg_color = 0xff; 
	int fg_color = 0xff0000; 
	
	/*set background*/
	memset(pixels, bg_color, SCRN_W * SCRN_H * 4);
	
	for(g = 0; g < grid_size*grid_size; g+= width*2)
	{
		for(w = 0; w < width; ++w)
		{
			/*draw pixel horizontal*/ 
			for(x = 0; x < SCRN_W; ++x)
			{	
				result = x + (SCRN_W *(w+(g)));
				if (result > SCRN_W * SCRN_H){break;}
				pixels[result] = fg_color; 
			}

			/*draw pixel vertical*/
			for(y = 0; y < SCRN_H; ++y)
			{
				result = (w+(g)) +(SCRN_W*y);
				if (result > SCRN_W * SCRN_H){break;}
				pixels[result] = fg_color;
			}
		}
	}
}	

void render()
{
	SDL_Event event;
	int q = 1; 

	while(q)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				case SDL_KEYDOWN:
					q = 0;
					break;
				default:
					break;
			}
		}

		SDL_UpdateWindowSurface(window);
	}
}

int main(int argc, char **argv)
{
	init();
	draw_grid((uint32_t *)screen->pixels, 8, 35);
	render();
	return 0; 
}
