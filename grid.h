#ifndef GRID_HEADER
#define GRID_HEADER
/**
 * @enum CaseType grid.h
 * @brief Information sur ce que chaque symbole represente
 * 
 */
enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' '
};
/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nomber de ligne de game_grid
};
/**
 * @brief
 * La fonction lit le fichier ligne par ligne pour mettre chaque caractere dans le tableau des entités présents
 * 
 * @param file_path Le chemin du fichier 
 * 
 * @return Grid 
 */
struct Grid init_level(const char* file_path);

#endif