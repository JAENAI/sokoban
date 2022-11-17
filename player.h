/**
 * @file player.h
 * @author Jaenai  Rugengande Ihimbazwe
 * @brief Fichier header player
 * @version 0.1
 * @date 2022-10-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PLAYER_HEADER
#define PLAYER_HEADER

typedef struct Grid Grid;

/**
 * @struct Player player.h
 * 
 * @brief 
 * La structure joueur contenant la position de celui-ci
 * 
 */
typedef struct Player{
    int x;///< Position par rapport à l'axe des abscisses
    int y;///< Position par rapport à l'axe des ordonnées
}Player;

/**
 * @enum Direction
 * 
 * @brief 
 * Les directions possibles du joueur
 * 
 */
typedef enum Direction{
    Top,
    Left,
    Right,
    Bottom
}Direction;

/**
 * @brief 
 * Fonction permettant le joueur de bouger dans une direction
 * 
 * @param g Un pointeur sur la structure grid contenant le niveau du jeu et ce qui y est
 * @param d Une direction
 */
void move_player(Grid* g,Direction d);

#endif