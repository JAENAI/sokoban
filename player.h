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

/**
 * @struct Player player.h
 * 
 * @brief 
 * La structure joueur contenant la position de celui-ci
 * 
 */
typedef struct Player{
    int x;
    int y;
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
 * La fonction prend en parametre une structure grid qui contient le joueur et une direction
 * La fonction amene le joueur dans une direction ce qui change egalement la position x et y du joueur
 * 
 * @param g1 
 * @param d 
 */
void move_player(Grid* g1,Direction d);

#endif