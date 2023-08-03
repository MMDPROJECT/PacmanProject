#ifndef MENU_FUNCTIONSHEADER
#define MENU_FUNCTIONSHEADER
#include <bits/stdc++.h>
#include "structs.hpp"
#include <string.h>
#include <string>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iostream>
#define cil ceil(((*game).size - 1) / 3)

using namespace std;

int showMenu                                                 ();
void NewGame_option                                          ();
void save_game                                               (Game * game, time_t& time_taken_to_finish);
void load_saves                                              ();
string spliter                                               (string s, string delimiter, int index);
void printOut_1                                              (Game * game_1);
void game_proccessing                                        (Game * game_1, time_t& time_taken_to_finish);
void check_pacman_and_ghost_turn_to_move                     (Game * game_1, int& count_while_loop, char& input);
void check_collision_with_ghosts                             (Game * game_1, int& count_while_loop);
void fruit_time_holder                                       (Game * game_1, int superpower_time_ofpacman, time_t& start_time_of_fruit_eating, int& check_count);
void ranking                                                 ();
bool compareTwoRanks                                         (const Ranking &a, const Ranking &b);
void computeRanks                                            (Ranking array_of_structures[], int size_of_array);
void game_struct_initializing_and_mapgenerator               (Game * game_1, int ** matrix, int size);
void initial_loaded_game                                     (Game * game_1);


#endif