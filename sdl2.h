#pragma once
#include <SDL2/SDL.h>
#include "grid.h"
/**
 *@brief
 *structure representant la fenetre de jeu
 *@struct SDLContext
 *
 */
typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;

/**
 *
 *@brief
 *Information sur les evenements
 *@enum Event
 *
 */
typedef enum Event{
	Quit,
	Left,
	Right,
	Up,
	Down,
	None	

}Event;

extern SDLContext context;

/**
 *@brief 
 * Initialise une variable global `context` de type SDLContext
 *
 * Si il y a erreur pendant l'intialisation:
 *  context.window = NULL
 *  ou 
 *  context.renderer = NULL
 *
 * Les deux cas sont à testé !
 * 
 */
void sdl_init();

/**
 * @brief
 * nettoie la variable global context 
 */
void sdl_quit();

/**
 *@brief
 *Affiche la grille de jeu avec SDL2
 *
 *@param Grid *g1
 *
 */
void display_sdl2(Grid *g1);

/**
 *
 *@brief 
 *Renvoie l'action à effectuer selon ce qui est touché sur le clavier
 *La gestion du clavier est effectué par la sdl2
 *@return Event
 */
 Event event_sdl2();
 
 /**
  *@brief
  *Renvoie l'action à effectuer selon ce qui est touché sur le clavier
  *La gestion du clavier est effectué par fgetc
  *@return Event
  */
 Event event();
 