#ifndef STRUCTSHEADER
#define STRUCTSHEADER
#include <time.h>
#include <string.h>
#include <string>

#define fruit_counts 4
#define superpower_time_of_pacman 10 //seconds

//structs
struct Pacman
{
    int i_initial;
    int j_initial;
    int i = i_initial;
    int j = j_initial;
    bool hasEatenFruit = false;
    int pacman_health = 3;
};
struct Ghosts
{
    int i_initial;
    int j_initial;
    int i = i_initial;
    int j = j_initial;
};
struct Game
{
    int ** matrix;
    int size;
    int remaining_dots;
    int i = 1;
    int j = 1;
    time_t time_taken_to_finish = 0;
    Pacman pacman;
    Ghosts ghost_1;
    Ghosts ghost_2;
    Ghosts ghost_3;
};
struct point
{
    int j;
    int i;
};
struct Ranking
{
    std::string user_name;
    time_t time_taken_to_finish;
    int rank;
    int mapsize;
    bool isGameFinished;
};

#endif