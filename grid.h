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
	int row_number; ///< Nombre de ligne de game_grid
	int ** pos_goal; ///< Les positions des goals
	int goal_number; ///< Le nombre des goals
	int covered_goals;///< Le nombre de goals recouverts
}Grid;
/**
 * @brief
 * La fonction lit le fichier ligne par ligne pour mettre chaque caractere dans le tableau des entités présents
 * Elle retourne une structure grid initialisé
 * 
 * @param file_path Le chemin du fichier 
 * 
 * @return Grid Une structure grid initialisé avec le niveau
 */
Grid init_level(const char* file_path);
/**
 * @brief 
 * La fonction affiche le niveau
 * 
 * @param g1 Un pointeur sur la structure grid contenant le niveau du jeu et ce qui y est
 */
void display(Grid *g1);
/**
 * @brief 
 * La fonction permet de verifier si tout les goals sont couverts
 * 
 * @param g1  Un pointeur sur la structure grid
 * @return true Retourner vrai si il y a tous les goals qui sont couverts
 * @return false Retourner faux si il n'y a pas tous les goals qui sont couverts
 */

bool check_covered_goals(Grid *g1);

#endif
