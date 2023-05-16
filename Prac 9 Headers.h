#ifndef PRAC_9_HEADERS_H_INCLUDED
#define PRAC_9_HEADERS_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <cctype>

using namespace std;
namespace SRISpace
{
    enum Errors
    {
        Err_argc = -1,
        Err_Conv = -2
    };

    enum Characters
    {
        empty_space,
        Immune,
        Recovered,
        Infected
    };

    typedef int* Arr_One;
    typedef int** Arr_two;

    const char Features[] = {'.', 'I', 'R', 'M'};

    struct Gamess
    {
        int Rows;
        int Columns;
        int infected_people;
        int Immune_people;
        int Recovered_people;
        Arr_two M_Array;
        int ImmuneRow;   //immune row
        int ImmuneCol;   //immune col
        int InfectedRow;  //infected row
        int InfectedCol;  //infected col
        int RcoveredRow;  // recovered person row
        int RcoveredCol;   // recoverd person col

        int ImmunePeople;
        int RecoveredPeople;
        int InfectedPeople;

        // counters of each character changes
        int Immune_count;
        int Infected_count;
        int Recovered_count;


    };

    //Basic simulation functions
    int string_Conv(string Word);
    Arr_two Memory_Allo(int Rows, int Columns);
    int Random_Generator(int lower, int Upper);
    void pause();
    Gamess Initialize_worls(int Rows, int Columns, int inf_Number, int im_number, int Re_number);
    void De_allocate(Arr_two& M_Array, int Rows);
    void place_Feature(Gamess& strcGame, int counter, int intFeature, int& Rows, int& Columns);
    void place_Immune(Gamess& strcGame, int number, int intFeaturee, int& Rows, int& Columns);
    void place_Recovered(Gamess& strcGame, int count_numb, int intFeatur, int& Rows, int& Columns);
    void printing_world(Gamess strcGame);

    bool is_in_World(int Rows, int Columns, int intRows, int intCols);

    // Functions that will handle movement for each character
    void Move_infected(Gamess& strcGame, int recovery_chance, int immunity_chances, int infect);
    void Move_immune(Gamess& strcGame);
    void Move_recovered(Gamess& strcGame);

    // Function that will handle the radius
    void Infectious_Range(Gamess& strcGame, int infect_rate);

    // Function that will handle the chance of infected being able to recover


    // Function that will handle the chance of infected being immune


}



#endif // PRAC_9_HEADERS_H_INCLUDED
