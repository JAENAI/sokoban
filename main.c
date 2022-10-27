#include <stdio.h>
#include "grid.h"
#include <stdbool.h>
int main(void){
	struct Grid g2=init_level("level1.txt");
	display(*g2);
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
		}
	}
	return 0;
}

