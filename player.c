#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void move_player(Grid* g,Direction d){
    int x1=g->p.x;
    int y1=g->p.y;
    switch(d){
        case Top:
            if(g->game_grid[y1+1][x1]=='$'&&g->game_grid[y1+2][x1]!='#'){
                g->p.y++;
                g->game_grid[y1+2][x1]='$';
                g->game_grid[y1+1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1+1][x1]==' '||g->game_grid[y1+1][x1]=='.'){
                g->p.y++;
                g->game_grid[y1+1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            break;
        case Left:
            if(g->game_grid[y1][x1-1]=='$'&&g->game_grid[y1][x1-2]!='#'){
                g->p.x--;
                g->game_grid[y1][x1-2]='$';
                g->game_grid[y1][x1-1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1][x1-1]==' '||g->game_grid[y1][x1-1]=='.'){
                g->p.x--;
                g->game_grid[y1][x1-1]='@';
                g->game_grid[y1][x1]=' ';
            }
            break;
        case Right:
            if(g->game_grid[y1][x1+1]=='$'&&g->game_grid[y1][x1+2]!='#'){
                g->p.x++;
                g->game_grid[y1][x1+2]='$';
                g->game_grid[y1][x1+1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1][x1+1]==' '||g->game_grid[y1][x1+1]=='.'){
                g->p.x++;
                g->game_grid[y1][x1+1]='@';
                g->game_grid[y1][x1]=' ';
            }
            break;
        case Bottom:
            if(g->game_grid[y1-1][x1]=='$'&&g->game_grid[y1-2][x1]!='#'){
                g->p.y--;
                g->game_grid[y1-2][x1]='$';
                g->game_grid[y1-1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            else if(g->game_grid[y1-1][x1]==' '||g->game_grid[y1-1][x1]=='.'){
                g->p.y--;
                g->game_grid[y1-1][x1]='@';
                g->game_grid[y1][x1]=' ';
            }
            break;
        default:
            break;
     }
    for(int i=0;i<g->goal_number;i++){
        if(g->pos_goal[i][0]==y1&&g->pos_goal[i][1]==x1){
            g->game_grid[y1][x1]='.';
        }
    }
}
