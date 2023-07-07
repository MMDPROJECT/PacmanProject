#include <iomanip>
#include "structs.hpp"
#include "mapgen.hpp"
#include "struct_functions.hpp"
#include "menu_functions.hpp"

using namespace std;

int main()
{
    int menu_option = showMenu ();      //show main menu with yellowed colour
    if (menu_option == 1)
    {
        NewGame_option();
    }
    else if (menu_option == 2)
    {
        load_saves ();
    }
    else if (menu_option == 3)
    {
        ranking ();
    }
    else if (menu_option == 4)
    {
        system ("color 4");
        cout << "\t\t\t\tGame Closed! " << "\u2639" << endl;
        Sleep (3000);
        system ("cls");
        system ("color 7");
    }
    
    return 0;
}
