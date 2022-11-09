#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void move_player(Grid* g,Direction d){
    int x1=g->p.x;
    int y1=g->p.y;
    int x_g;
    int y_g;
    switch(d){
        case Top:
            if(g->game_grid[y1+1][x1]=='$'&&g->game_grid[y1+2][x1]!='#'){
                if(g->game_grid[y1+2][x1]=='.'){
                    x_g=x1;
                    y_g=y1+2;
                }
                g->game_grid[y1+2][x1]='$';
                g->game_grid[y1+1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1+1][x1]=='.'){
                x_g=x1;
                y_g=y1+1;
                g->game_grid[y1+1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1+1][x1]==' '){
                g->game_grid[y1+1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            if(x1==x_g&&y1==y_g){
                g->game_grid[x1][y1]='.';
            }
            break;
        case Left:
            if(g->game_grid[y1][x1-1]=='$'&&g->game_grid[y1][x1-2]!='#'){
                if(g->game_grid[y1][x1-2]=='.'){
                    x_g=x1-2;
                    y_g=y1;
                }
                g->game_grid[y1][x1-2]='$';
                g->game_grid[y1][x1-1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1][x1-1]=='.'){
                x_g=x1-1;
                y_g=y1;
                g->game_grid[y1][x1-1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1][x1-1]==' '){
                g->game_grid[y1][x1-1]='@';
                g->game_grid[y1][x1]=' ';
            }
            if(x1==x_g&&y1==y_g){
                g->game_grid[y1][x1]='.';
            }
            break;
        case Right:
            if(g->game_grid[y1][x1+1]=='$'&&g->game_grid[y1][x1+2]!='#'){
                if(g->game_grid[y1][x1+2]=='.'){
                    x_g=x1+2;
                    y_g=y1;
                }
                g->game_grid[y1][x1+2]='$';
                g->game_grid[y1][x1+1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1][x1+1]=='.'){
                x_g=x1+1;
                y_g=y1;
                g->game_grid[y1][x1+1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1][x1+1]==' '){
                g->game_grid[y1][x1+1]='@';
                g->game_grid[y1][x1]=' ';
            }
            if(x1==x_g&&y1==y_g){
                g->game_grid[y1][x1]='.';
            }
            break;
        case Bottom:
            if(g->game_grid[y1-1][x1]=='$'&&g->game_grid[y1-2][x1]!='#'){
                if(g->game_grid[y1-2][x1]=='.'){
                    x_g=x1;
                    y_g=y1-2;
                }
                g->game_grid[y1-2][x1]='$';
                g->game_grid[y1-1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1-1][x1]=='.'){
                x_g=x1;
                y_g=y1-1;
                g->game_grid[y1-1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            if(x1==x_g&&y1==y_g){
                g->game_grid[y1][x1]='.';
            }
            break;
        default:
            break;
     }
}
