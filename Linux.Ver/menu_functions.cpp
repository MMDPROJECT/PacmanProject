#include "struct_functions.hpp"
#include "menu_functions.hpp"
#include "mapgen.hpp"
#include "structs.hpp"
#include <time.h>
#include <fstream>
#include <iomanip>
#include <termios.h>
#include <sys/select.h>


bool kbhit() {
    struct termios oldSettings, newSettings;
    int ch;

    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    int result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    return (result == 1 && FD_ISSET(STDIN_FILENO, &readfds));
}


int showMenu                                   ()
{
    system ("clear");                 
    cout << "\033[1;33m";                                         //make the screen yellow
    cout << "PLEASE CHOOSE ONE OPTION BY IT'S NUMBER. " << endl
         << "1.New Game"  << endl
         << "2.Load Game" << endl
         << "3.Ranking"   << endl
         << "4.Exit"      << endl;
    int menu_option;
    cin >> menu_option;
    system ("clear");
    cout << ("\033[0m");                                         //make the screen white (back to original colour)
    return menu_option;
}
void NewGame_option                            ()
{
    int size;                                                               //declaring size of the map
    cout << ("\033[1;34m");                                                     //change the color to blue
    cout << "Please enter an integer between 20 and 40 to begin..." << endl;
    cin >> size;                                                            //input size of the map
    system ("clear");
    cout << ("\033[0m");                                                     //make the color white (back to original color)
    int ** matrix = new int *[size];                                        // declaring our 2D int pointer

    for (int i = 0; i < size; i++)
    {
        matrix [i] = new int [size];
    }
    initial_all_the_elements_to_wall (matrix, size);        
    int i = 1;                                          //starter point (could be change to anything in region 1)
    int j = 1;
    matrix[i][j] = 0;                                   

    Game * game_1 = new Game; 
    game_struct_initializing_and_mapgenerator (game_1, matrix, size);

    time_t time_taken_to_finish = time (NULL);
    game_proccessing (game_1, time_taken_to_finish);       
    return;
}
void save_game                                 (Game* game, time_t& time_taken_to_finish)
{
    string username;
    system("clear");
    cout << ("\033[1;34m");
    cout << "Could you please enter your name: " << endl;
    cin  >> username;
    fstream file_handle;
    file_handle.open ("saves.txt", ios::app | ios::in);
    string delimiter_1 = " ";
    string delimiter_2 = ",";
    file_handle << "Game "          << username << " ";
    if ( calc_remaining_dots (game) == 0)
    {
        file_handle << "YES";
    }
    else
    {
        file_handle << "NO";
    }
    file_handle << "\n";
    file_handle <<  (*game).size    << delimiter_2 << (*game).pacman.i << delimiter_2 << (*game).pacman.j << delimiter_2 << (*game).pacman.i_initial << delimiter_2 << (*game).pacman.j_initial << delimiter_2 << (*game).pacman.hasEatenFruit << delimiter_2 << (*game).pacman.pacman_health  << delimiter_2 << (*game).ghost_1.i << delimiter_2 << (*game).ghost_1.j << delimiter_2 << (*game).ghost_1.i_initial << delimiter_2 << (*game).ghost_1.j_initial << delimiter_2 << (*game).ghost_2.i << delimiter_2 << (*game).ghost_2.j << delimiter_2 << (*game).ghost_2.i_initial << delimiter_2 << (*game).ghost_2.j_initial << delimiter_2 << (*game).ghost_3.i << delimiter_2 << (*game).ghost_3.j << delimiter_2 << (*game).ghost_3.i_initial << delimiter_2 << (*game).ghost_3.j_initial << "\n";
    for (int i = 0; i < (*game).size; i++)
    {
        for (int j = 0; j < (*game).size; j++)
        {
            file_handle << (*game).matrix [i][j] << delimiter_2;
        }
        file_handle << "\n";
    }
    file_handle << "time_taken:" << (*game).time_taken_to_finish << "\n";
    // file_handle << "Game_Completed:";
    // if (game->remaining_dots == 0)
    // {
    //     file_handle << "YES";
    // }
    // else
    // {
    //     file_handle << "NO";
    // }
    // file_handle << "\n";
    file_handle.close();
}
void load_saves                                ()
{
    Game * game_1 = new Game;
    initial_loaded_game (game_1);
    int count_while_loop = 0;
    int count_test = 0;
    char input = 'd';
    time_t time_taken_to_finish = time (NULL);
    game_proccessing (game_1, time_taken_to_finish);
}
string spliter                                 (string s, string delimiter, int index){
    string token_result;
    int start, end = -1 * delimiter.size(); int counter = 0;

    while (counter != index){

        start = end + delimiter.size();
        end = s.find (delimiter, start);
        token_result = s.substr (start, end - start);
        counter++;
    }
    return token_result;
}
void printOut_1                                (Game * game)
{
//0:Dot            , 1:Inner Walls     , 2:First Row Of Walls , 3:Last Row Of Walls,  4: First Column Of Walls, 5:Last Column Of Walls
//6:Top Left Corner, 7:Top Right Corner, 8:Bottom Right Corner, 9:Bottom Left Corner, 10:Fruit, 11:Empty Space, 20:House Of the Devils
    for (int i = 0; i < (*game).size; i++) {
        cout << "\t\t\t\t";
        for (int j = 0; j < (*game).size; j++)
        {
            if (i == (*game).pacman.i && j == (*game).pacman.j)
            {
                if ((*game).pacman.hasEatenFruit == false)
                {
                    cout << "\u263A";
                }
                else
                {
                    cout << "\u2694";
                }
            }
            else if (i == (*game).ghost_1.i && j == (*game).ghost_1.j)
            {
                cout << "\u2620";
            }
            else if (i == (*game).ghost_2.i && j == (*game).ghost_2.j)
            {
                cout << "\u2620";
            }
            else if (i == (*game).ghost_3.i && j == (*game).ghost_3.j)
            {
                cout << "\u2620";
            }
            else if ((*game).matrix[i][j] == 0)
            {
                cout << ".";
            }
            else if ((*game).matrix[i][j] == 1)
            {
                cout << "\u2588";
            }
            else if ((*game).matrix[i][j] == 2)
            {
                cout << "\u2500";
            }
            else if ((*game).matrix[i][j] == 3)
            {
                cout << "\u2500";
            }
            else if ((*game).matrix[i][j] == 4)
            {
                cout << "\u2502";
            }
            else if ((*game).matrix[i][j] == 5)
            {
                cout << "\u2502";
            }
            else if ((*game).matrix[i][j] == 6)
            {
                cout << "\u250C";
            }
            else if ((*game).matrix[i][j] == 7)
            {
                cout << "\u2510";
            }
            else if ((*game).matrix[i][j] == 8)
            {
                cout << "\u2518";
            }
            else if ((*game).matrix[i][j] == 9)
            {
                cout << "\u2514";
            }
            else if ((*game).matrix[i][j] == 10)
            {
                cout << "\u2766";
            }
            else if ((*game).matrix[i][j] == 20)
            {
                cout << "\u256C";
            }
            else if ((*game).matrix[i][j] == 11)
            {
                cout << " ";
            }
//            cout << " ";
        }
        cout << endl;
    }
    // cout << endl << endl;
}//print out the array after generating ways
void game_proccessing(Game* game_1, time_t& time_taken_to_finish) {
    int count_while_loop = 0;
    int check_count = 0;
    char input = 'd';

    while ((*game_1).remaining_dots != 0) {
        usleep(85000);
        time_t start_of_fruit_eating_time;
        (*game_1).remaining_dots = calc_remaining_dots(game_1);
        system("clear");
        printOut_1(game_1);
        std::cout << std::endl
                  << std::setw(5) << "Health: " << (*game_1).pacman.pacman_health
                  << std::setw(20) << "time taken: " << time(NULL) - time_taken_to_finish;
        count_while_loop++;

        check_pacman_and_ghost_turn_to_move(game_1, count_while_loop, input);
        check_collision_with_ghosts(game_1, count_while_loop);
        eat_dot(game_1);
        eat_fruit(game_1);
        fruit_time_holder(game_1, superpower_time_of_pacman, start_of_fruit_eating_time, check_count);

        if (kbhit()) {
            input = getchar();
            if (input == 'v') {
                system("clear");
                (*game_1).time_taken_to_finish += (time(NULL) - time_taken_to_finish);
                save_game(game_1, time_taken_to_finish);
                std::cout << "saving..." << std::endl;
                usleep(2000000);
                system("clear");
                std::cout << "game successfully saved";
                usleep(3000000);
                system("clear");
                return;
            }
        }
    }

    system("clear");
    std::cout << "YOU WON" << std::endl;
    usleep(3000000);

    (*game_1).time_taken_to_finish += (time(NULL) - time_taken_to_finish);
    save_game(game_1, (*game_1).time_taken_to_finish);
    usleep(4000000);
    system("./a.out");

    return;
}

void check_pacman_and_ghost_turn_to_move       (Game * game_1, int& count_while_loop, char& input)
{
    if (count_while_loop % 4 == 0 && count_while_loop > 40)
    {
        ghosts_random_move (game_1,game_1->ghost_1.i, game_1->ghost_1.j);
        ghosts_random_move (game_1,game_1->ghost_2.i, game_1->ghost_2.j);
        ghosts_random_move (game_1,game_1->ghost_3.i, game_1->ghost_3.j);
    }
    if (count_while_loop % 3 == 0)
    {
        pacman_movement    (game_1, input);
    }
}

void check_collision_with_ghosts               (Game *game_1, int& count_while_loop)
{
    if (((*game_1).pacman.i == (*game_1).ghost_1.i && (*game_1).pacman.j == (*game_1).ghost_1.j))
    {
        collision_with_ghost_1 (game_1, count_while_loop);
    }
    if (((*game_1).pacman.i == (*game_1).ghost_2.i && (*game_1).pacman.j == (*game_1).ghost_2.j))
    {
        collision_with_ghost_2 (game_1, count_while_loop);
    }
    if (((*game_1).pacman.i == (*game_1).ghost_3.i && (*game_1).pacman.j == (*game_1).ghost_3.j))
    {
        collision_with_ghost_3 (game_1, count_while_loop);
    }
}

void fruit_time_holder                         (Game *game_1, int superpower_time_ofpacman, time_t& start_time_of_fruit_eating, int& check_count)
{
    if (check_count == 0 && game_1->pacman.hasEatenFruit == true)
    {
        check_count ++;
        start_time_of_fruit_eating = time (NULL);
    }
    if (time(NULL) == superpower_time_ofpacman + start_time_of_fruit_eating && check_count == 1)
    {
        check_count = 0;
        game_1->pacman.hasEatenFruit = false;
    }
}

void ranking                                   ()
{
    fstream file_handler;
    file_handler.open ("saves.txt", ios::in);
    string line;
    string wordi;
    struct Ranking array_of_structures[10];
    int counter = 0;

    // while (getline (file_handler, line))
    // {
    //     // cout << line << endl;
    //     wordi = spliter (line, " ", 1);
    //     if (wordi == "Game")
    //     {
    //         array_of_structures [counter].user_name = spliter (line, " ", 2);
    //         while (getline (file_handler, line))
    //         {
    //             wordi = spliter (line, ":", 1);
    //             if (wordi == "time_taken")
    //             {
    //                 array_of_structures [counter].time_taken_to_finish = stoi (spliter (line, ":", 2));
    //                 getline (file_handler, line);
    //                 if (spliter (line, ":", 2) == "YES")
    //                 {
    //                     array_of_structures [counter].isGameFinished = true;
    //                 }
    //                 else
    //                 {
    //                     array_of_structures [counter].isGameFinished = false;
    //                 }
    //                 counter++;
    //                 break;
    //             }
                
    //         }
    //     }
    // }
    while (getline (file_handler, line))
    {
        
        wordi = spliter (line, " ", 1);
        {
            if (wordi == "Game" && spliter (line, " ", 3) == "YES")
            {
                array_of_structures[counter].user_name = spliter (line, " ", 2);
                while (getline (file_handler, line))
                {
                    wordi = spliter (line, ":", 1);
                    if (wordi == "time_taken")
                    {
                        array_of_structures[counter].time_taken_to_finish = stoi(spliter (line, ":", 2));
                        counter++;
                    }
                }
            }
        }
    }
    computeRanks (array_of_structures, counter);
    cout << ("\033[0;34m");
    cout << setw (10) << "RANK" << setw(20) << "NAME OF SAVES" << setw(20) << "TIME TAKEN" << endl; 
    for (int i = 0; i < counter; i++)
    {
        // if (array_of_structures[i].isGameFinished == true)
        // {
            cout << setw(7) << i + 1 << "." << setw(17) <<  array_of_structures [i].user_name << " " << setw(18) << array_of_structures [i].time_taken_to_finish << endl;
        // }
    }
    file_handler.close ();
}

bool compareTwoRanks                           (const Ranking &a, const Ranking &b)
{
    if (b.time_taken_to_finish < a.time_taken_to_finish)
    {
        return 1;
    }
    else if (b.mapsize < a.mapsize)
    {
        return 1;
    }
    return 0;
}

void computeRanks                              (Ranking array_of_structures[], int size_of_array)
{
    sort (array_of_structures, array_of_structures + size_of_array, &compareTwoRanks);

    for (int i = 0; i < size_of_array; i++)
    {
        array_of_structures[i].rank = i + 1;
    }
}

void game_struct_initializing_and_mapgenerator (Game * game_1, int ** matrix, int size)
{
    (*game_1).matrix = matrix;                              //initilizing struct of game attributes
    (*game_1).size = size;      
    (*game_1).remaining_dots = calc_remaining_dots (game_1);

    (*game_1).pacman.i_initial = floor ((3 * size) / 4);    //initilizing i, j current and it's initial positions for pacman
    (*game_1).pacman.j_initial = floor (size / 2);
    (*game_1).pacman.i = (*game_1).pacman.i_initial;
    (*game_1).pacman.j = (*game_1).pacman.j_initial;

    (*game_1).ghost_1.i_initial = ceil (size / 4) + 1;          //initilizing i, j current and it's initial positions for ghost_1
    (*game_1).ghost_1.j_initial = ceil (size / 2) - 1;
    (*game_1).ghost_1.i         = (*game_1).ghost_1.i_initial;
    (*game_1).ghost_1.j         = (*game_1).ghost_1.j_initial;

    (*game_1).ghost_2.i_initial = ceil (size / 4) + 1;          //initilizing i, j current and it's initial positions for ghost_2
    (*game_1).ghost_2.j_initial = ceil (size / 2);
    (*game_1).ghost_2.i         = (*game_1).ghost_2.i_initial;
    (*game_1).ghost_2.j         = (*game_1).ghost_2.j_initial;

    (*game_1).ghost_3.i_initial = ceil (size / 4) + 1;          //initilizing i, j current and it's initial positions for ghost_3
    (*game_1).ghost_3.j_initial = ceil (size / 2) + 1;
    (*game_1).ghost_3.i         = (*game_1).ghost_3.i_initial;
    (*game_1).ghost_3.j         = (*game_1).ghost_3.j_initial;

    call_all_the_region_ways (game_1);                  
    call_all_intersections   (game_1);
    frame_generator          (game_1);
    int ii ; int jj ;
    pacman_way_generator     (game_1, ii, jj);
    ghost_house              (game_1);
    
    fruit_spawning (game_1, fruit_counts);
}
void initial_loaded_game                       (Game * game_1)
{
    fstream file_handler;
    file_handler.open ("saves.txt", ios::in);
    string line;
    string wordi;
    bool weGetToLine = false;
    cout << ("\033[0;35m");
    cout << "please select one of these saves: " << endl;
    while (getline (file_handler, line))
    {
        // cout << line << endl;
        wordi = spliter (line, " ", 1);
        if (wordi == "Game")
        {
            cout << spliter (line, " ", 2) << endl;
        }
    }

    string savename_input;
    cin >> savename_input;
    system ("clear");
    file_handler.close();
    file_handler.open ("saves.txt", ios::in);
    // 

    while (getline (file_handler, line))
    {
        wordi = spliter (line, " ", 2);
        if (wordi == savename_input)
        {
            weGetToLine = true;
            continue;
        }
        if (weGetToLine == true)
        {
            cout << ("\033[0;35m");
            cout << savename_input << " is loading..." << endl;
            sleep (1500);
            system ("clear");
            cout << ("\033[0m");
            (*game_1).size = stoi (spliter (line, ",", 1));
            int** matrix = new int *[(*game_1).size];         // declaring our 2D int pointer

            for (int i = 0; i < (*game_1).size; i++)
            {
                matrix [i] = new int [(*game_1).size];
            }
            (*game_1).matrix = matrix;
            (*game_1).pacman.i = stoi (spliter (line, ",", 2));
            (*game_1).pacman.j = stoi (spliter (line, ",", 3));
            (*game_1).pacman.i_initial = stoi (spliter (line, ",", 4));
            (*game_1).pacman.j_initial = stoi (spliter (line, ",", 5));
            if ((spliter (line, ",", 6)) != "0")
            {
                (*game_1).pacman.hasEatenFruit = true;
            }
            (*game_1).pacman.pacman_health = stoi (spliter (line, ",", 7));
            (*game_1).ghost_1.i = stoi (spliter (line, ",", 8));
            (*game_1).ghost_1.j = stoi (spliter (line, ",", 9));
            (*game_1).ghost_1.i_initial = stoi (spliter (line, ",", 10));
            (*game_1).ghost_1.j_initial = stoi (spliter (line, ",", 11));

            (*game_1).ghost_2.i = stoi (spliter (line, ",", 12));
            (*game_1).ghost_2.j = stoi (spliter (line, ",", 13));
            (*game_1).ghost_2.i_initial = stoi (spliter (line, ",", 14));
            (*game_1).ghost_2.j_initial = stoi (spliter (line, ",", 15));

            (*game_1).ghost_3.i = stoi (spliter (line, ",", 16));
            (*game_1).ghost_3.j = stoi (spliter (line, ",", 17));
            (*game_1).ghost_3.i_initial = stoi (spliter (line, ",", 18));
            (*game_1).ghost_3.j_initial = stoi (spliter (line, ",", 19));
            for (int i = 0; i < (*game_1).size; i++)
            {
                getline (file_handler, line);
                for (int j = 0; j < (*game_1).size; j++)
                {
                    (*game_1).matrix[i][j] = stoi(spliter (line, ",", j + 1));
                }
            }
            getline (file_handler, line);
            (*game_1).time_taken_to_finish = stoi (spliter(line, ":", 2));
            file_handler.close();
        }
    }
}