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
  //Synth aSynth();

  //  for ( int i =0; i < 20; i++ )
  //cout << "doing something" << endl;

  SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);

  //do something video
  SDL_Window* window = SDL_CreateWindow("woo woo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  SDL_UpdateWindowSurface(window);
  SDL_Delay(2000);

  SDL_DestroyWindow(window);
  SDL_Quit();
}

