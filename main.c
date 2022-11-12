#include <stdio.h>
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
				run = false;
				break;
			}
		}
	}
	return 0;
}

