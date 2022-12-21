#include "sdl2.h"

SDLContext context;

void sdl_init() {
  int const width = 1280;
  int const height = 720;
  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO)) {
    return;
  }

  SDL_Window *window =
      SDL_CreateWindow("Sokoban", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (!window) {
    return;
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
}

void sdl_quit() {
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}

void display_sdl2(Grid *g1){
  SDL_SetRenderDrawColor(context.renderer,0,0,0,255);// Couleur de fond
  SDL_RenderClear(context.renderer);
  for(int i=0;i<g1->row_number;i++){
  	for(int j=0;j<g1->column_number;j++){
  		if(g1->game_grid[i][j]=='#'){
  			SDL_SetRenderDrawColor(context.renderer,100,100,100,255);
  			SDL_Rect wall={
  				.x=j*(1280/g1->column_number),
  				.y=i*(720/g1->row_number),
  				.w=1280/g1->column_number,
  				.h=720/g1->row_number
  				};
  			SDL_RenderFillRect(context.renderer,&wall);
  			}
  		else if(g1->game_grid[i][j]=='$'){
  			SDL_SetRenderDrawColor(context.renderer,255,255,255,255);
  			SDL_Rect box={
  				.x=j*(1280/g1->column_number),
  				.y=i*(720/g1->row_number),
  				.w=1280/g1->column_number,
  				.h=720/g1->row_number
  				};
  			SDL_RenderFillRect(context.renderer,&box);
  			}
  		else if(g1->game_grid[i][j]=='.'){
  			SDL_SetRenderDrawColor(context.renderer,255,0,0,255);
  			SDL_Rect goal={
  				.x=j*(1280/g1->column_number),
  				.y=i*(720/g1->row_number),
  				.w=(1280/2)/g1->column_number,
  				.h=(720/2)/g1->row_number
  				};
  			SDL_RenderFillRect(context.renderer,&goal);
  			}
  		else if(g1->game_grid[i][j]=='@'){
  			SDL_SetRenderDrawColor(context.renderer,0,0,200,255);
  			SDL_Rect player={
  				.x=j*(1280/g1->column_number),
  				.y=i*(720/g1->row_number),
  				.w=1280/g1->column_number,
  				.h=720/g1->row_number
  				};
  			SDL_RenderFillRect(context.renderer,&player);
  			}
  		}
  	}
  SDL_RenderPresent(context.renderer);

}

Event event_sdl2(){
  SDL_Event event1;
  SDL_WaitEvent(&event1);
  switch(event1.type){
    case SDL_QUIT:
      return Quit;
    case SDL_KEYUP:
      switch(event1.key.keysym.sym){
        case SDLK_DOWN:
          return Down;
        case SDLK_UP:
          return Up;
        case SDLK_LEFT:
          return Left1;
        case SDLK_RIGHT:
          return Right1;
        default:
          return None;
      }
    default:
      return None;
  }
}