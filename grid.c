#include "grid.h"
#include <stdlib.h>
#include <stdio.h>
#include "player.h"
struct Grid init_level(const char* file_path){
	// ouverture du fichier en mode lecture
	struct Grid * g=(struct Grid*)malloc(sizeof(struct Grid*));
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1).
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; /// nombre de ligne
	int number_goals = 0;
	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	g->game_grid=(enum CaseType**)malloc(sizeof(enum CaseType*)*number_row*number_column);
	g->column_number=number_column;
	g->row_number=number_row;
	int current_row = 0;
	int current_goal = 0;
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			g->game_grid[current_row][current_column]=*buffer;
			current_column += 1;
			buffer += 1;
			if(*buffer=='.'){
				current_goal+=1;
			}
		}		
		current_row += 1;
	}
	// fermeture du fichier
	fclose(file);
	return *g;
}
