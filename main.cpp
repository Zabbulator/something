#include<iostream>
#include "SDL.h"        // SDL-Header
#include "SDL_opengl.h" // Bindet plattformabhängig die richtigen Header ein

using std::cout;
using std::endl;

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

  // Fenstertitel setzen:
  // Der erste Text steht in der Titelleiste des Fensters und der zweite in der Taskleiste.
  SDL_WM_SetCaption( "Tomprogs Game Tutorials - First Try", "Tomprogs - First Try" );

  // Doublebuffering aktivieren
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

  // Ein OpenGL Fenster mit einer Auflösung von 800*600 Pixeln und
  // einer Farbtiefe von 32 Pixeln erzeugen.
  SDL_SetVideoMode( 800, 600, 32, SDL_OPENGL );
  
  while(true)
  {
    SDL_Event event; // Hier wird immer die neue Nachricht gespeichert
  
    while( SDL_PollEvent(&event) ) // Holen der nächsten Nachricht
    {
      // Bestimmen des Nachrichtentyps
      switch(event.type)
      {
        // Bei einer SDL_QUIT Nachricht sollte das Programm beendet werden.
        // Sie wird zb. verschickt wenn man auf das X beim Programmfenster
        // klickt.
        case SDL_QUIT:
          SDL_Quit(); // Herunterfahren der SDL
          exit(0);
          break;
        default:
          break;
      }
    }

  // Hierher kommt dann alles was das Spiel am Laufen hält...

  }
  
  SDL_Quit(); // Herunterfahren der SDL Bibliotheken
  return 0;
}