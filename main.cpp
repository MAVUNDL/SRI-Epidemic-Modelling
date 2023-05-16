#include "Prac 9 Headers.h"
#include <iostream>

using namespace std;
using namespace SRISpace;

int main(int argc, char** argv)
{
    if(argc != 9)
    {
        cerr << "The number of arguemnts is either greater or lower than the expected number of arguements" << endl;
        exit(Err_argc);
    }

    // my variables
    int rows = string_Conv(argv[1]);
    int cols = string_Conv(argv[2]);
    int infection_chance = string_Conv(argv[3]);
    int recovery_chance = string_Conv(argv[4]);
    int immune_chance = string_Conv(argv[5]);
    int number_Infected = string_Conv(argv[6]);
    int number_Recovering = string_Conv(argv[7]);
    int number_Immune = string_Conv(argv[8]);


    // my array
    Gamess strcGame = Initialize_worls(rows, cols, number_Infected, number_Immune,number_Recovering);

    //other variables
    bool blnContinue = true;
    char chInput = '\0';

    do
    {
        //printing the world
        printing_world(strcGame);

        // handling the menu system
        cout << "Your selection: ";
        cin >> chInput;

        switch(chInput)
        {
            case 'a':
                {
                    Move_infected(strcGame, recovery_chance, immune_chance,infection_chance);
                    Move_immune(strcGame);
                    Move_recovered(strcGame);

                }
                break;
            case 'b':
                {
                    blnContinue = false;
                    cout << "\nStatistics after simulation\n" << endl;
                    cout << "People who were infected: " << strcGame.Infected_count << endl;
                    cout << "People who recovered: " << strcGame.Recovered_count << endl;
                    cout << "People who became immune: " << strcGame.Immune_count << endl;

                }
                break;
            default:
                cerr << "Invalid option, try again" << endl;
                break;

        }


        // handling the end game

    }
    while(blnContinue);

    // de allocate memory
    De_allocate(strcGame.M_Array, rows);


    return 0;
}
