#include <stdio.h>
#include "grid.h"
#include <stdbool.h>
int main(void){
	char* file;
	scanf("%s",file);
	printf("\n");
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
	init_level(file);
	return 0;
}

