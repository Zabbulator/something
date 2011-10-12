#include<iostream>
#include "SDL.h"        // SDL-Header
#include "SDL_opengl.h" // Bindet plattformabhängig die richtigen Header ein

// Die main Funktion muss unter Windows unbedingt
// diese Form haben, da es ansonsten zu einem
// Linkerfehler kommen würde.
int main(int argc, char **argv)
{
  if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) // Initialisieren des SDL Video Subsystems
  {
    cout << "Die SDL konnte nicht initalisiert werden (" << SDL_GetError() << ")" << endl;
    return 1;
  }

  cout << "Willkommen zum SDL Testprogramm." << endl;


  SDL_Quit(); // Herunterfahren der SDL Bibliotheken
  return 0;
}