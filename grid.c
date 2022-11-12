#include "grid.h"
#include <stdlib.h>
#include <stdio.h>
Grid init_level(const char* file_path){
	// ouverture du fichier en mode lecture
	Grid* g=(Grid*)malloc(sizeof(Grid));
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; /// nombre de ligne
	int number_goals = 0;
	// on lit la première ligne du fichier et on enregistre les tailles de notre tableau de jeu
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	g->game_grid=malloc(number_row*sizeof(CaseType*));
	for(int i=0;i<number_row;i++){
		g->game_grid[i]=malloc(number_column*sizeof(CaseType));
	}
	g->column_number=number_column;
	g->row_number=number_row;
	int current_row = 0;
	int current_goal=0;
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier et on met dans notre tableau de jeu les caracteres ligne par ligne
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			g->game_grid[current_row][current_column]=*buffer;
			if(*buffer=='.'){
				number_goals+=1;
			}
			if(*buffer=='@'){
				g->p.x=current_column+1;
				g->p.y=number_row-current_row;
			}
			current_column += 1;
			buffer +=1;
		}		
		current_row+=1;
	}
	//On sauvegarde de la position des goals
	g->goal_number=number_goals;
	g->pos_goal=malloc(number_goals*sizeof(int*));
	for(int i=0;i<number_goals;i++){
		g->game_grid[i]=malloc(2*sizeof(int));
	}
	for(int i=0;i<number_row;i++){
		for(int j=0;j<number_column;j++){
			if(g->game_grid[i][j]=='.'){
				g->pos_goal[current_goal][0]=i;
				g->pos_goal[current_goal][1]=j;
				current_goal+=1;
			}
		}
	}
	// fermeture du fichier
	fclose(file);
	return *g;
}

void display(Grid* g1){
	for(int i=0; i<g1->row_number;i++){
		for(int j=0; j<g1->column_number;j++){
			printf("%c",g1->game_grid[i][j]);
		}
		printf("\n");
	}
}
