#ifndef MAPGENHEADER
#define MAPGENHEADER


#include "structs.hpp"
#include <string.h>
#include <string>
#include <cmath>
#include <fstream>
#include <unistd.h>    
#include <ncurses.h>
#include <iostream>


using namespace std;

// Prototype of functions
void initial_all_the_elements_to_wall        (int ** matrix, int size);
void mazeWay1_3                              (Game * game);  //generate a way from regin 2 to region 3
void mazeWay3_5                              (Game * game);  //generate a way from regin 4 to region 5
void mazeWay5_7                              (Game * game);  //generate a way from regin 6 to region 7
void mazeWay7_1                              (Game * game);  //generate a way from regin 8 to region 1
void call_all_the_region_ways                (Game * game);  //call all maze generators one by one

void point_in_region_1                       (Game * game);
void intersection_from_region1               (Game * game, int& wall_point_i, int& wall_point_j);

void point_in_region_2                       (Game * game);
void intersection_from_region2               (Game * game, int& wall_point_i, int& wall_point_j);

void point_in_region_3_to_down               (Game * game);
void intersection_from_region3_to_down       (Game * game, int& wall_point_i, int& wall_point_j);

void point_in_region_region_3_to_left        (Game * game);
void intersection_from_region3_to_left       (Game * game, int& wall_point_i, int& wall_point_j);

void point_in_region_4                       (Game * game);
void intersection_from_region4               (Game * game, int& wall_point_i, int& wall_point_j);

void point_in_region_5                       (Game * game);
void intersection_from_region5               (Game * game, int& wall_point_i, int& wall_point_j);

void pacman_way_generator                    (Game * game, int& i, int& j);  //generate a way from pacman position to the main road
void call_all_intersections                  (Game * game);

void ghost_house                             (Game * game);  //house of ghosts and opening their way to maze
void house_creation                          (Game * game);
void ghost_way_generator                     (Game * game);

void horizental_head_and_tail_walls          (Game * game);
void vertical_head_and_tail_walls            (Game * game);
void four_corners                            (Game * game);
void frame_generator                         (Game * game);

#endif