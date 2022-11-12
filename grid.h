#ifndef GRID_HEADER
#define GRID_HEADER
#include "player.h"
/**
 * @enum CaseType grid.h
 * @brief Information sur ce que chaque symbole represente
 * 
 */
typedef enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' '
}CaseType;
/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
typedef struct Grid{
	Player p; ///< La position du joueur
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nomber de ligne de game_grid
	int ** pos_goal; ///< Les positions des goals
}Grid;
/**
 * @brief
 * La fonction lit le fichier ligne par ligne pour mettre chaque caractere dans le tableau des entités présents
 * 
 * @param file_path Le chemin du fichier 
 * 
 * @return Grid 
 */
struct Grid init_level(const char* file_path);
/**
 * @brief 
 * La fonction affiche le niveau
 * 
 * @param g1 Adresse du niveau
 */
void display(struct Grid *g1);

#endif
