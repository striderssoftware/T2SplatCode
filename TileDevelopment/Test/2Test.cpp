#include <iostream>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <list>
#include <unistd.h> 

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

int main()
{

  cout << "running splay" << endl;

      static char envvars[][50] =
	{
	 //"SDL_NOMOUSE=1",
	 //"TSLIB_CONSOLEDEVICE=none",
	 //"TSLIB_TSDEVICE=/dev/input/event1",
	 //"SDL_VIDEODRIVER=directfb",
	 //"SDL_MOUSEDRV=TSLIB",
	 //"SDL_MOUSEDEV=/dev/input/event1",
	 //"SDL_NO_RAWKBD=1",
	 "XDG_RUNTIME_DIR=/run/user/1000",
	               0
	};
      for (unsigned int i = 0; i < sizeof(envvars)/sizeof(envvars[0]); ++i)
	if (putenv(envvars[i])) abort();

      cout << "Set envvars" <<endl;

  if ( SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0 )
    {
      cout << "SDL_Init Error" << endl;
      cout << SDL_GetError() << endl;
    }



   SDL_Window * window = SDL_CreateWindow("",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_RESIZABLE);

    SDL_Surface * window_surface = SDL_GetWindowSurface(window);

    unsigned int * pixels = (unsigned int*)window_surface->pixels;
    int width = window_surface->w;
    int height = window_surface->h;

    printf("Pixel format: %s\n",
        SDL_GetPixelFormatName(window_surface->format->format));

    //while (1)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) exit(0);
            if (event.type == SDL_WINDOWEVENT)
            {
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    window_surface = SDL_GetWindowSurface(window);
                    pixels = (unsigned int *)window_surface->pixels;
                    width = window_surface->w;
                    height = window_surface->h;
                    printf("Size changed: %d, %d\n", width, height);
                }
            }
        }

        // Set every pixel to white.
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                pixels[x + y * width] =
                    SDL_MapRGBA(window_surface->format, 200, 100, 250, 255);
            }
        }

        SDL_UpdateWindowSurface(window);
    }


    SDL_Delay(9000);


  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();


    
}

