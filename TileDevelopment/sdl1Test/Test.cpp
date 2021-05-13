#include <iostream>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <list>
#include <unistd.h> 

#include <SDL/SDL.h>


using namespace std;

int main()
{

  cout << "running splay" << endl;


  if ( SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0 )
    {
      cout << "SDL_Init Error" << endl;
      cout << SDL_GetError() << endl;
    }


  SDL_Surface* surface = SDL_SetVideoMode(800, 800, 32, SDL_SWSURFACE); //SDL_DOUBLEBUF | SDL_FULLSCREEN)

  

  SDL_Rect* rect = new SDL_Rect();

  SDL_WM_SetCaption("say bow wow for yogie", "yogie");

  SDL_GetClipRect(surface, rect);

  for ( int i = 0; i < 2; i++ )
    {
      SDL_FillRect(surface, rect, SDL_MapRGB(surface->format, 10*i %255, (100*i)%255, 167) );
      
      SDL_Flip(surface);
      SDL_Delay(6000);
      
    }
  
  
  SDL_Surface* image;
  SDL_Surface* temp;
  temp = SDL_LoadBMP("./MagicTheature.bmp");

  image = SDL_DisplayFormat(temp);


  SDL_Rect src, dest;


  src.x = 0; src.y = 0;
  src.w = 800; // image->w;
  src.h = 800; //image->h;

  dest.x = 0; dest.y = 0;
  dest.w = 800; //image->w;
  dest.h = 800; //image->h;
  
  SDL_BlitSurface(image, &src, surface , &dest);

  SDL_Flip(surface);
  
  SDL_Delay(2000);


  SDL_FreeSurface(image);
  SDL_FreeSurface(temp);
  
  SDL_Quit();
  
}

