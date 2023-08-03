#ifndef STRUCT_FUNCTIONSHEADER
#define STRUCT_FUNCTIONSHEADER
#include <time.h>
#include <cmath>
#include "structs.hpp"
#include <iostream>
#include <windows.h>
#include <conio.h>


int  calc_remaining_dots                          (Game* game);
void creatures_movement                           (char input, int& i, int& j);
bool is_move_allowed                              (Game * game,int i, int j, char input);
void pacman_movement                              (Game * game, char input);
void ghosts_random_move                           (Game * game, int& i, int& j);
void bring_back_all_to_initial_position           (Game * game);
void collision_with_ghost_1                       (Game * game, int& count_while_loop);
void collision_with_ghost_2                       (Game * game, int& count_while_loop);
void collision_with_ghost_3                       (Game * game, int& count_while_loop);
void fruit_spawning                               (Game * game, int fruit_starting_counts);
void eat_dot                                      (Game * game);
void eat_fruit                                    (Game * game);
void pacman_health_minus                          (Game * game);

#endif