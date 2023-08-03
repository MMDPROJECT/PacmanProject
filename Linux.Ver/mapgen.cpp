#include "struct_functions.hpp"
#include "menu_functions.hpp"
#include "mapgen.hpp"
#include "structs.hpp"

void initial_all_the_elements_to_wall        (int ** matrix, int size)
{
    for (int i = 0; i < size; i++)          //initializing our 2D array
    {
        for (int j = 0; j < size; j++)
        {
            matrix [i][j] = 1;
        }
    }  
}
void mazeWay1_3                              (Game * game)
{
    int rand_int;
    while (true)
    {
        rand_int = abs(rand() % 7);
        if (rand_int == 0 || rand_int == 5)
        {
            if ((*game).i != 1)
            {
                (*game).i --;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                mazeWay1_3(game);
            }
        }
        if (rand_int == 1 || rand_int == 3 || rand_int == 4 || rand_int == 6)
        {
            if ((*game).j != (*game).size - 2)
            {
                (*game).j ++;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_int == 2)
        {
            if ((*game).i != (ceil(((*game).size) - 1) / 3) - 1)
            {
                (*game).i++;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                mazeWay1_3(game);
            }
        }
        if ((*game).j == (*game).size - 2 )
        {
            break;
        }
    }
}   
void mazeWay3_5                              (Game * game)
{
    int rand_int ;
    while (true)
    {
        rand_int = abs(rand() % 5);
        if (rand_int == 0 || rand_int == 3)
        {
            if ((*game).j != (*game).size - 2)
            {
                (*game).j++;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                mazeWay3_5 (game);
            }
        }

        if (rand_int == 1 )
        {
            if ((*game).i != (*game).size - 2)
            {
                (*game).i++;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                break;
            }
        }

        if (rand_int == 2)
        {
            if ( (*game).j != 2 * ceil ( ((*game).size - 1) / 3) + 1)
            {
                (*game).j--;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                mazeWay3_5 (game);
            }
        }

        if ((*game).i == (*game).size - 2)
        {
            break;
        }
    }
}
void mazeWay5_7                              (Game * game)
{
    int rand_int;
    while (true)
    {
        rand_int = abs(rand() % 6);
        if (rand_int == 0 || rand_int == 5)
        {
            if ((*game).i != (*game).size - 2)
            {
                (*game).i++;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                mazeWay5_7(game);
            }
        }

        if (rand_int == 1 || rand_int == 3 || rand_int == 4)
        {
            if ((*game).j != floor((ceil(((*game).size - 1) / 3)) / 2) )
            {
                (*game).j--;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                break;
            }
        }

        if (rand_int == 2)
        {
            if ((*game).i != 2 * (ceil(((*game).size - 1) / 3)) )
            {
                (*game).i--;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                mazeWay5_7(game);
            }
        }

        if ((*game).j == floor((ceil(((*game).size - 1) / 3)) / 2))
        {
            break;
        }
    }
}
void mazeWay7_1                              (Game * game)
{
    int rand_int;
    while(true)
    {
        rand_int = abs(rand() % 6);
        if (rand_int == 0 || rand_int == 5)
        {
            if ((*game).j != 1)
            {
                (*game).j--;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                mazeWay7_1(game);
            }
        }

        if (rand_int == 1 || rand_int == 3 || rand_int == 4)
        {
            if ((*game).i != 2)
            {
                (*game).i--;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                break;
            }
        }

        if (rand_int == 2)
        {
            if ((*game).j != ceil(((*game).j - 1) / 3))
            {
                (*game).j++;
                (*game).matrix[(*game).i][(*game).j] = 0;
            }
            else
            {
                mazeWay7_1(game);
            }
        }

        if ((*game).i == 2)
        {
            break;
        }
    }
}  
void call_all_the_region_ways                (Game * game)
{
    srand(time(0));
    mazeWay1_3(game);
    mazeWay3_5(game);
    mazeWay5_7(game);
    mazeWay7_1(game);
}
void point_in_region_1                       (Game * game)
{
    point wall_point;
    int rand_num;
    rand_num = fmod(rand(), cil);
    wall_point;
    wall_point.j = rand_num;
    wall_point.i = 1;
    intersection_from_region1(game, wall_point.i, wall_point.j); 
}
void intersection_from_region1               (Game * game, int& wall_point_i, int& wall_point_j)
{
    (*game).matrix[wall_point_i][wall_point_j] = 0;
    while (true)
    {
        int rand_num = rand() % 5;
        if (rand_num == 0)
        {
            if (wall_point_j != (*game).size - 2)
            {
                wall_point_j ++;
                (*game).matrix [wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region1 (game, wall_point_i, wall_point_j);
            }
        }
        if (rand_num == 1 || rand_num == 2 || rand_num == 3)
        {
            if (wall_point_i != (*game).size - 2)
            {
                wall_point_i++;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_num == 4)
        {
            if (wall_point_j != 1)
            {
                wall_point_j--;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region1 (game, wall_point_i, wall_point_j);
            }
        }
        if (wall_point_i == (*game).size - 2)
        {
            break;
        }
    }
}
void point_in_region_2                       (Game * game)
{
    point wall_point;
    int rand_num;
    rand_num = fmod(rand(), cil) + cil;
    wall_point;
    wall_point.j = rand_num;
    wall_point.i = 1;
    intersection_from_region2(game, wall_point.i, wall_point.j);
}
void intersection_from_region2               (Game * game, int& wall_point_i, int& wall_point_j)
{
    (*game).matrix[wall_point_i][wall_point_j] = 0;
    while (true)
    {
        int rand_num = rand() % 5;
        if (rand_num == 0)
        {
            if (wall_point_j != (*game).size - 2)
            {
                wall_point_j ++;
                (*game).matrix [wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region2 (game, wall_point_i, wall_point_j);
            }
        }
        if (rand_num == 1 || rand_num == 2 || rand_num == 3)
        {
            if (wall_point_i != (*game).size - 2)
            {
                wall_point_i++;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_num == 4)
        {
            if (wall_point_j != 1)
            {
                wall_point_j--;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region2 (game, wall_point_i, wall_point_j);
            }
        }
        if (wall_point_i == (*game).size - 2)
        {
            break;
        }
    }
}
void point_in_region_3_to_down               (Game * game)
{
    point wall_point;
    int rand_num;
    rand_num = fmod(rand(), cil)+ 2 * cil;
    wall_point;
    wall_point.j = rand_num;
    wall_point.i = 1;
    intersection_from_region3_to_down(game, wall_point.i, wall_point.j); 
}
void intersection_from_region3_to_down       (Game * game, int& wall_point_i, int& wall_point_j)

{
    (*game).matrix[wall_point_i][wall_point_j] = 0;
    while (true)
    {
        int rand_num = rand() % 5;
        if (rand_num == 0)
        {
            if (wall_point_j != (*game).size - 2)
            {
                wall_point_j ++;
                (*game).matrix [wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region3_to_down (game, wall_point_i, wall_point_j);
            }
        }
        if (rand_num == 1 || rand_num == 2 || rand_num == 3)
        {
            if (wall_point_i != (*game).size - 2)
            {
                wall_point_i++;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_num == 4)
        {
            if (wall_point_j != 1)
            {
                wall_point_j--;
               (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region3_to_down (game, wall_point_i, wall_point_j);
            }
        }
        if (wall_point_i == (*game).size - 2)
        {
            break;
        }
    }
}
void point_in_region_3_to_left               (Game * game)
{
    point wall_point;
    int rand_num;
    rand_num = fmod(rand(), cil);
    wall_point;
    wall_point.j = (*game).size - 2;
    wall_point.i = rand_num;
    intersection_from_region4(game, wall_point.i, wall_point.j); 
}
void intersection_from_region3_to_left       (Game * game, int& wall_point_i, int& wall_point_j)
{
    (*game).matrix[wall_point_i][wall_point_j] = 0;
    while (true)
    {
        int rand_num = rand() % 5;
        if (rand_num == 0)
        {
            if (wall_point_i != (*game).size - 2)
            {
                wall_point_i ++;
                (*game).matrix [wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region3_to_left (game, wall_point_i, wall_point_j);
            }
        }
        if (rand_num == 1 || rand_num == 2 || rand_num == 3)
        {
            if (wall_point_j != 1)
            {
                wall_point_j --;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_num == 4)
        {
            if (wall_point_i != 1)
            {
                wall_point_i--;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region3_to_left (game, wall_point_i, wall_point_j);
            }
        }
        if (wall_point_j == 1)
        {
            break;
        }
    }
}
void point_in_region_4                       (Game * game)
{
    point wall_point;
    int rand_num;
    rand_num = fmod(rand(), cil) + cil;
    wall_point;
    wall_point.j = (*game).size - 2;
    wall_point.i = rand_num;
    intersection_from_region4(game, wall_point.i, wall_point.j); 
}
void intersection_from_region4               (Game * game, int& wall_point_i, int& wall_point_j)
{
    (*game).matrix[wall_point_i][wall_point_j] = 0;
    while (true)
    {
        int rand_num = rand() % 5;
        if (rand_num == 0)
        {
            if (wall_point_i != (*game).size - 2)
            {
                wall_point_i ++;
                (*game).matrix [wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region4 (game, wall_point_i, wall_point_j);
            }
        }
        if (rand_num == 1 || rand_num == 2 || rand_num == 3)
        {
            if (wall_point_j != 1)
            {
                wall_point_j --;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_num == 4)
        {
            if (wall_point_i != 1)
            {
                wall_point_i--;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region4 (game, wall_point_i, wall_point_j);
            }
        }
        if (wall_point_j == 1)
        {
            break;
        }
    }
}
void point_in_region_5                       (Game * game)
{
    point wall_point;
    int rand_num;
    rand_num = fmod(rand(), cil) + 2 * cil;
    wall_point;
    wall_point.j = (*game).size - 2;
    wall_point.i = rand_num;
    intersection_from_region5        (game, wall_point.i, wall_point.j); 
}
void intersection_from_region5               (Game * game, int& wall_point_i, int& wall_point_j)
{
    (*game).matrix[wall_point_i][wall_point_j] = 0;
    while (true)
    {
        int rand_num = rand() % 5;
        if (rand_num == 0)
        {
            if (wall_point_i != (*game).size - 2)
            {
                wall_point_i ++;
                (*game).matrix [wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region5 (game, wall_point_i, wall_point_j);
            }
        }
        if (rand_num == 1 || rand_num == 2 || rand_num == 3)
        {
            if (wall_point_j != 1)
            {
                wall_point_j --;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_num == 4)
        {
            if (wall_point_i != 1)
            {
                wall_point_i--;
                (*game).matrix[wall_point_i][wall_point_j] = 0;
            }
            else
            {
                intersection_from_region5 (game, wall_point_i, wall_point_j);
            }
        }
        if (wall_point_j == 1)
        {
            break;
        }
    }
}

void pacman_way_generator                    (Game * game, int& i, int& j)
{
    int i_pacman = floor((3 * (*game).size)/ 4);
    int j_pacman = floor((*game).size/ 2);
    i = i_pacman;
    j = j_pacman;
    while (true)
    {
        int rand_int = abs(rand() % 12);
        if (rand_int == 0 || rand_int == 1 || rand_int == 2 || rand_int == 8)
        {
            if (j != 1)
            {
                j--;
                (*game).matrix[i][j] = 0;
            }
            else
            {
                break;
            }
        }

        if (rand_int == 3 || rand_int == 4 || rand_int == 5 || rand_int == 9 )
        {
            if (j != (*game).size - 2)
            {
                j++;
                (*game).matrix[i][j] = 0;
            }
            else
            {
                break;
            }
        }

        if (rand_int == 6 || rand_int == 10 )
        {
            if (i != 1)
            {
                i--;
                (*game).matrix[i][j] = 0;
            }
            else
            {
                break;
            }
        }

        if (rand_int == 7 || rand_int == 11)
        {
            if (i != (*game).size - 2)
            {
                i++;
                (*game).matrix[i][j] = 0;
            }
            else
            {
                break;
            }
        }

        if (j == 1 || j == (*game).size - 2 || i == (*game).size - 2 || i == 1 )
        {
            break;
        }
    }
    (*game).matrix[i_pacman][j_pacman] = 0;
}

void call_all_intersections                  (Game * game)
{
    point_in_region_1         (game);
    point_in_region_2         (game);
    point_in_region_3_to_down (game);
    point_in_region_3_to_left (game);
    point_in_region_4         (game);
    point_in_region_5         (game);
}

void house_creation                          (Game * game)
{
    const int i_of_door = ceil((*game).size / 4);
    const int j_of_door = ceil((*game).size / 2);

    (*game).matrix [i_of_door][j_of_door] = 0;
    (*game).matrix [i_of_door][j_of_door + 1] = 20;
    (*game).matrix [i_of_door][j_of_door + 2] = 20;
    (*game).matrix [i_of_door + 1][j_of_door + 2] = 20;
    (*game).matrix [i_of_door + 2][j_of_door + 2] = 20;
    (*game).matrix [i_of_door + 2][j_of_door + 1] = 20;
    (*game).matrix [i_of_door + 2][j_of_door    ] = 20;
    (*game).matrix [i_of_door + 2][j_of_door - 1] = 20;
    (*game).matrix [i_of_door + 2][j_of_door - 2] = 20;
    (*game).matrix [i_of_door + 1][j_of_door - 2] = 20;
    (*game).matrix [i_of_door  ][j_of_door - 1] = 20;
    (*game).matrix [i_of_door  ][j_of_door - 2] = 20;
    (*game).matrix [i_of_door + 1][j_of_door ] = 0;
    (*game).matrix [i_of_door + 1][j_of_door + 1] = 0;
    (*game).matrix [i_of_door + 1][j_of_door - 1] = 0;
}
void ghost_way_generator                     (Game * game)
{
    const int i_of_door = ceil((*game).size / 4);
    const int j_of_door = ceil((*game).size / 2);
    int i = i_of_door - 1;
    int j = j_of_door;
    (*game).matrix[i][j] = 0;
    while (true)
    {
        int rand_num = rand() % 7;
        if (rand_num == 0 || rand_num == 1 || rand_num == 2)
        {
            if (j != 1)
            {
                j--;
                (*game).matrix[i][j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_num == 3)
        {
            if (i != 1)
            {
                i--;
                (*game).matrix[i][j] = 0;
            }
            else
            {
                break;
            }
        }
        if (rand_num == 4 || rand_num == 5 || rand_num == 6)
        {
            if (j != (*game).size - 2)
            {
                j++;
                (*game).matrix[i][j] = 0;
            }
            else
            {
                break;
            }
        }
        if (j == 1 || i == 1 || j == (*game).size -2)
        {
            break;
        }
    }
}
void ghost_house                             (Game * game)
{
    house_creation      (game);
    ghost_way_generator (game);
}

void horizental_head_and_tail_walls          (Game * game)
{
    for (int i = 0 ; i < (*game).size ; i++)
    {
        for (int j = 0; j < (*game).size ; j++)
        {
            if (i == 0)
            {
                (*game).matrix[i][j] = 2;
            }
            if (i == ((*game).size - 1))
            {
                (*game).matrix[i][j] = 3;
            }
        }
        
    }
}
void vertical_head_and_tail_walls            (Game * game)
{
    for (int i = 0 ; i < (*game).size ; i++)
    {
        for (int j = 0; j < (*game).size ; j++)
        {
            if (j == 0)
            {
                (*game).matrix[i][j] = 4;
            }
            if (j == ((*game).size - 1))
            {
               (*game).matrix[i][j] = 5;
            }
        }
        
    }
}
void four_corners                            (Game * game)
{
    for (int i = 0; i < (*game).size; i++)
    {
        for (int j = 0; j < (*game).size; j++)
        {
            if (i == 0 && j == 0)               (*game).matrix[i][j] = 6;
            if (i == (*game).size - 1 && j == 0)        (*game).matrix[i][j] = 9;
            if (i == 0 && j == (*game).size - 1)        (*game).matrix[i][j] = 7;
            if (i == (*game).size - 1 && j == (*game).size - 1) (*game).matrix[i][j] = 8;
        }
    }
}
void frame_generator                         (Game * game)
{
    horizental_head_and_tail_walls  (game);
    vertical_head_and_tail_walls    (game);
    four_corners                    (game);
}