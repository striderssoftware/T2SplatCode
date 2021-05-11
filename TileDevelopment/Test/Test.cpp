#include <iostream>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <list>
#include <unistd.h> 

#include <SDL2/SDL.h>

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

  //do something video
  //SDL_Window* window = SDL_CreateWindow("say bow wow for yogie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, SDL_WINDOW_SHOWN);
  SDL_Window* window = SDL_CreateWindow("say bow wow for yogie", 32, 32, 200, 200, SDL_WINDOW_SHOWN);

  if ( window == nullptr )
    {
      cout << "SDL_CreateWindow Error" << endl;
      cout << SDL_GetError() << endl;
    }


  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  // Select the color for drawing. It is set to red here.
  //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  
  // Clear the entire screen to our selected color.
  SDL_RenderClear(renderer);

  SDL_Surface* image = SDL_LoadBMP("/MagicTheature.bmp");
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  
  // Up until now everything was drawn behind the scenes.
  // This will show the new, red contents of the window.
  SDL_RenderPresent(renderer);
  

  SDL_UpdateWindowSurface(window);
  SDL_Delay(9000);


  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

