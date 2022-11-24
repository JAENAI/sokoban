#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include <stdbool.h>
int main(void){
	Grid g2=init_level("level1.txt");
	display(&g2);
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'h':
				move_player(&g2,Left);
				display(&g2);
				break;
			case 'j':
				move_player(&g2,Bottom);
				display(&g2);
				break;
			case 'k':
				move_player(&g2,Top);
				display(&g2);
				break;
			case 'l':
				move_player(&g2,Right);
				display(&g2);
				break;
			case 'q' :{
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
			break;
		}
	}
	return 0;
}

