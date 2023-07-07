#include "struct_functions.hpp"
#include "structs.hpp"
#include "menu_functions.hpp"

using namespace std;

int  calc_remaining_dots                    (Game * game)
{

    int dot_counts = 0;
    for (int i = 0; i < (*game).size; i++)
    {
        for (int j = 0; j < (*game).size; j++)
        {
            if ((*game).matrix[i][j] == 0)
            {
                dot_counts ++;
            }
        }
    }
    return dot_counts;
}
void creatures_movement                     (char input, int& i, int& j)
{
    switch (input)
    {
        case 'a':
            j--;
            break;
        case 'w':
            i--;
            break;
        case 'd':
            j++;
            break;
        case 's':
            i++;
            break;
    }
}
bool is_move_allowed                        (Game * game,int i, int j, char input)
{
    bool is_allowed = true;
    if (input == 'a')
    {
        if ((*game).matrix[i][j - 1] == 1 || (*game).matrix[i][j - 1] == 20 || (*game).matrix[i][j - 1] == 2 || (*game).matrix[i][j - 1] == 3 || (*game).matrix[i][j - 1] == 4 || (*game).matrix[i][j - 1] == 5)
        {
            is_allowed = false;
        }
    }
    else if (input == 'w')
    {
        if ((*game).matrix[i - 1][j] == 1 || (*game).matrix[i  - 1][j] == 20 || (*game).matrix[i  - 1][j] == 2 || (*game).matrix[i  - 1][j] == 3 || (*game).matrix[i  - 1][j] == 4 || (*game).matrix[i  - 1][j] == 5)
        {
            is_allowed = false;
        }
    }
    else if (input == 'd')
    {
        if ((*game).matrix[i][j + 1] == 1 || (*game).matrix[i][j + 1] == 20 || (*game).matrix[i][j + 1] == 2 || (*game).matrix[i][j + 1] == 3 || (*game).matrix[i][j + 1] == 4 || (*game).matrix[i][j + 1] == 5)
        {
            is_allowed = false;
        }
    }
    else if (input == 's')
    {
        if ((*game).matrix[i + 1][j] == 1 || (*game).matrix[i + 1][j] == 20 || (*game).matrix[i + 1][j] == 2 || (*game).matrix[i + 1][j] == 3 || (*game).matrix[i + 1][j] == 4 || (*game).matrix[i + 1][j] == 5)
        {
            is_allowed = false;
        }
    }
    return is_allowed;
}
void pacman_movement                        (Game * game, char input)
{
    bool move_allowed;
    if (input == 'a')
    {
        move_allowed = is_move_allowed (game, game->pacman.i, game->pacman.j, 'a');
        if (move_allowed == true)
        {
            creatures_movement ('a', game->pacman.i, game->pacman.j);
        }
    }
    if (input == 'w')
    {
        move_allowed = is_move_allowed (game, game->pacman.i, game->pacman.j, 'w');
        if (move_allowed == true)
        {
            creatures_movement ('w', game->pacman.i, game->pacman.j);
        }
    }
    if (input == 'd')
    {
        move_allowed = is_move_allowed (game, game->pacman.i, game->pacman.j, 'd');
        if (move_allowed == true)
        {
            creatures_movement ('d', game->pacman.i, game->pacman.j);
        }
    }
    if (input == 's')
    {
        move_allowed = is_move_allowed (game, game->pacman.i, game->pacman.j, 's');
        if (move_allowed == true)
        {
            creatures_movement ('s', game->pacman.i, game->pacman.j);
        }
    }
}
void ghosts_random_move                     (Game * game, int& i, int& j)
{
    int rand_int = rand() % 4; //0 means go the left, 1 means go the Top, 2 means go the Right, 3 means go the the Bottom
    bool move_allowed;
    if (rand_int == 0)
    {
        move_allowed = is_move_allowed (game, i, j, 'a');
        if (move_allowed == true)
        {
            creatures_movement ('a', i, j);
        }
    }
    else if (rand_int == 1)
    {
        move_allowed = is_move_allowed (game, i, j, 'w');
        if (move_allowed == true)
        {
            creatures_movement ('w', i, j);
        }
    }
    else if (rand_int == 2)
    {
        move_allowed = is_move_allowed (game, i, j, 'd');
        if (move_allowed == true)
        {
            creatures_movement ('d', i, j);
        }
    }
    else if (rand_int == 3)
    {
        move_allowed = is_move_allowed (game, i, j, 's');
        if (move_allowed == true)
        {
            creatures_movement ('s', i, j);
        }
    }
}
void bring_back_all_to_initial_position     (Game * game)
{
    system ("cls");
    system ("color 4");
    cout << "\t\t\t\t\t" << "\u2639" << "  YOU ARE WASTED " << "\u2639" << endl;
    Sleep (4000);
    system ("color 7");
    system ("cls");

    game->pacman.i = game->pacman.i_initial;
    game->pacman.j = game->pacman.j_initial;

    game->ghost_1.i = game->ghost_1.i_initial;
    game->ghost_1.j = game->ghost_1.j_initial;

    game->ghost_2.i = game->ghost_2.i_initial;
    game->ghost_2.j = game->ghost_2.j_initial;

    game->ghost_3.i = game->ghost_3.i_initial;
    game->ghost_3.j = game->ghost_3.j_initial;
}
void collision_with_ghost_1                 (Game * game, int& count_while_loop)
{
    if ((*game).pacman.hasEatenFruit == true)
    {
        game->ghost_1.i = game->ghost_1.i_initial;
        game->ghost_1.j = game->ghost_1.j_initial;
    }
    else
    {
        pacman_health_minus (game);
        bring_back_all_to_initial_position (game);
    }
    // count_while_loop = 0;

}
void collision_with_ghost_2                 (Game * game, int& count_while_loop)
{
    if ((*game).pacman.hasEatenFruit == true)
    {
        game->ghost_2.i = game->ghost_2.i_initial;
        game->ghost_2.j = game->ghost_2.j_initial;
    }
    else
    {
        pacman_health_minus (game);
        bring_back_all_to_initial_position (game);
    }
    // count_while_loop = 0;
}
void collision_with_ghost_3                 (Game * game, int& count_while_loop)
{
    if ((*game).pacman.hasEatenFruit == true)
    {
        game->ghost_3.i = game->ghost_3.i_initial;
        game->ghost_3.j = game->ghost_3.j_initial;
    }
    else
    {
        pacman_health_minus (game);
        bring_back_all_to_initial_position (game);
    }
    // count_while_loop = 0;
}
void fruit_spawning                         (Game * game, int fruit_starting_counts)
{
    for (int i = 0; i < fruit_starting_counts; i++)
    {
        int rand_i;
        int rand_j;
        while (true)
        {
            rand_i = (rand() % ((*game).size - 3)) + 1;
            rand_j = (rand() % ((*game).size - 3)) + 1;
            if ((*game).matrix[rand_i][rand_j] == 0)
            {
                (*game).matrix[rand_i][rand_j] = 10;
                break;
            }
        }
    }

}
void eat_dot                                (Game * game)
{
    if ((*game).matrix[(*game).pacman.i][(*game).pacman.j] == 0)
    {
        (*game).matrix [(*game).pacman.i][(*game).pacman.j] = 11;
    }
}
void eat_fruit                              (Game * game)
{
    if ((*game).matrix[(*game).pacman.i][(*game).pacman.j] == 10)
    {
        game->pacman.hasEatenFruit = true;
        (*game).matrix[(*game).pacman.i][(*game).pacman.j] = 11;
    }
}

void pacman_health_minus                    (Game * game)
{
    (*game).pacman.pacman_health -- ;
    if ((*game).pacman.pacman_health == 0)
    {
        system ("cls");
        system ("color 4");
        cout << "\t\t\t\t" << "pacman died!" << "\u2689" << endl;
        cout << "  " << "\t\t\t" << "\u271E" << " MY CONDOLENCES TO YOU " << "\u271E" << endl;
        Sleep (4000);
        system ("color 7");
        system ("cls");
        system ("a.exe");
    }
}