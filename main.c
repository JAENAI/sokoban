#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "sdl2.h"
#include <stdbool.h>
#include <string.h>

int main(int argc,char **argv){
	Event (*handle_event)();
	void (*handle_display)(Grid*);
	bool run= true;
	Grid g2=init_level("level1.txt");
	if(argc==1){
		handle_event=&event;
		handle_display=&display;
		(*handle_display)(&g2);
		while(run){
			Event ev=(*handle_event)();
			switch(ev){	
				case Left1:
					move_player(&g2,Left);
					(*handle_display)(&g2);
					break;
				case Down:					
					move_player(&g2,Bottom);
					(*handle_display)(&g2);
					break;
				case Up:
					move_player(&g2,Top);
					(*handle_display)(&g2);
					break;
				case Right1:
					move_player(&g2,Right);
					(*handle_display)(&g2);
					break;			
				case None:
					break;
				case Quit :{
					for(int i=0;i<g2.row_number;i++){
						free(g2.game_grid[i]);
						}
					free(g2.game_grid);
					for(int j=0;j<g2.goal_number;j++){
						free(g2.pos_goal[j]);
						}
					free(g2.pos_goal);
					run = false;
					break;
					}
				}
			if(check_covered_goals(&g2)){
				run=false;
				}
		}
	}
	else{
		if(strcmp(argv[1],"--sdl2")==0){
			handle_event=&event_sdl2;
			handle_display=&display_sdl2;
			sdl_init();
			(*handle_display)(&g2);
			while(run){
				Event ev=(*handle_event)();
				switch(ev){
					case Left1:
						move_player(&g2,Left);
						(*handle_display)(&g2);
						break;
					case Down:
						move_player(&g2,Bottom);
						(*handle_display)(&g2);
						break;
					case Up:
						move_player(&g2,Top);
						(*handle_display)(&g2);
						break;
					case Right1:
						move_player(&g2,Right);
						(*handle_display)(&g2);
						break;
					case None:
							break;
					case Quit :{
						for(int i=0;i<g2.row_number;i++){
							free(g2.game_grid[i]);
						}
						free(g2.game_grid);
						for(int j=0;j<g2.goal_number;j++){
						free(g2.pos_goal[j]);
						}
						free(g2.pos_goal);
						run = false;
						break;
					}
				}
				if(check_covered_goals(&g2)){
					run=false;
				}
			}
			sdl_quit();
		}
	
		else if(strcmp(argv[1],"--console")==0){
			handle_event=&event;
			handle_display=&display;
			(*handle_display)(&g2);
			while(run){
				Event ev=(*handle_event)();
				switch(ev){	
					case Left1:
						move_player(&g2,Left);
						(*handle_display)(&g2);
						break;
					case Down:
						move_player(&g2,Bottom);
						(*handle_display)(&g2);
						break;
					case Up:
						move_player(&g2,Top);
						(*handle_display)(&g2);
						break;
					case Right1:
						move_player(&g2,Right);
						(*handle_display)(&g2);
						break;
					case None:
						break;
					case Quit :{
						for(int i=0;i<g2.row_number;i++){
							free(g2.game_grid[i]);
						}
						free(g2.game_grid);
						for(int j=0;j<g2.goal_number;j++){
							free(g2.pos_goal[j]);
						}
						free(g2.pos_goal);
						run = false;
						break;
					}
				}
				if(check_covered_goals(&g2)){
					run=false;
				}
			}
		}
	
		else{
			printf("Les arguments ne sont pas valides");
		}
	}
	return 0;
}

