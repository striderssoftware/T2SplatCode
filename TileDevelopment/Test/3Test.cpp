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


  // Create stuff
   SDL_Window * window = SDL_CreateWindow("woo woo",
					  0,0, //SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					  720, 480,
        SDL_WINDOW_RESIZABLE);


   // Set every pixel.
   SDL_Surface * window_surface = SDL_GetWindowSurface(window);
   SDL_Surface* image = SDL_LoadBMP("./MagicTheature.bmp");      
   //int width = image->w;
   //int height = image->h;  //6700 opt
   int width = window_surface->w;
   int height = window_surface->h;

   cout << "Width:" << width << endl;
   cout << "Height:" << height << endl;
   unsigned int * surfacePixels=  (unsigned int*)window_surface->pixels;
 
   unsigned int * imagePixels = (unsigned int*)image->pixels;

        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
	      // surfacePixels[x + y * width] =
	      //SDL_MapRGBA(window_surface->format, 200, 100, 250, 255);

	      surfacePixels[x + y * width] = imagePixels[x + y * width]; 
		  
            }
	}
   

   SDL_UpdateWindowSurface(window);
   
   
   SDL_Delay(5000);
   
   
   SDL_DestroyWindow(window);



   TTF_Quit();
   SDL_Quit();
    
}

