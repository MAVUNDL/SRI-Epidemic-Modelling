#include "Prac 9 Headers.h"

namespace SRISpace
{
    int string_Conv(string Word)
    {
        int Term = 0;

        stringstream ss {Word};
        ss >> Term;

        if(ss.fail())
        {
            cerr << "Could not convert " << Term << " to an integer" << endl;
            exit(Err_Conv);
        }
        return Term;
    }

     int Random_Generator(int lower, int Upper)
     {
         srand(time(nullptr));

         int Range = Upper - lower + 1;

         return rand()%Range+lower;
     }

     void pause()
     {
         cin.ignore(100, '\n');
         cerr << "Press enter to continue" << endl;
         cin.get();
     }

     Arr_two Memory_Allo(int Rows, int Columns)
     {
         Arr_two M_array;
         M_array = new Arr_One[Rows];

         for(int i = 0; i < Rows; i++)
         {
             M_array[i] = new int[Columns];
             for(int n = 0; n < Columns; n++)
             {
                 M_array[i][n] = empty_space;
             }
         }
         return M_array;
     }

     Gamess Initialize_worls(int Rows, int Columns, int inf_Number, int im_number, int Re_number)
     {
         // name our struct
         Gamess strcGame;

         // give it memory
         strcGame.M_Array = Memory_Allo(Rows,Columns);

         // setting initial values
         strcGame.Rows = Rows;
         strcGame.Columns = Columns;
         strcGame.infected_people;
         strcGame.Immune_people;
         strcGame.Recovered_people;

         //my struct rows and cols
         strcGame.InfectedRow;
         strcGame.InfectedCol;

         strcGame.ImmuneRow;
         strcGame.ImmuneCol;

         strcGame.RcoveredRow;
         strcGame.RcoveredCol;

         // Give initial statistics at first before simulation
         strcGame.ImmunePeople = im_number;
         strcGame.infected_people = inf_Number;
         strcGame.RecoveredPeople = Re_number;

         // Update after simulation
         strcGame.Immune_count = 0;
         strcGame.Recovered_count = 0;
         strcGame.Infected_count = 0;

         //I place my infected characters
         place_Feature(strcGame, inf_Number, Infected, Rows, Columns);

         // I place my immune characters
         place_Immune(strcGame, im_number, Immune, Rows, Columns);

         // I place my recovered characters
         place_Recovered(strcGame,Re_number, Recovered, Rows, Columns);


         return strcGame;
     }

     void De_allocate(Arr_two& M_Array, int Rows)
     {
         assert(M_Array != nullptr);
         for(int i = 0; i < Rows; i++)
            delete[]  M_Array[i];
         delete [] M_Array;
         M_Array = nullptr;
     }

     // This function will place my infected characters in the world
    void place_Feature(Gamess& strcGame, int counter, int intFeature, int& Rows, int& Columns)
    {
        srand(time(nullptr));
        for(int n = 0; n < counter; n++)
        {
            strcGame.InfectedRow = rand()% strcGame.Rows;
            strcGame.InfectedCol = rand()% strcGame.Columns;

            while(strcGame.M_Array[strcGame.InfectedRow][strcGame.InfectedCol] != empty_space)
            {
                strcGame.InfectedRow = rand()% strcGame.Rows;
                strcGame.InfectedCol = rand()% strcGame.Columns;
            }
            strcGame.M_Array[strcGame.InfectedRow][strcGame.InfectedCol] = intFeature;
        }
    }

    // THis function will place my immune characters in the world
    void place_Immune(Gamess& strcGame, int number, int intFeaturee, int& Rows, int& Columns)
    {
        srand(time(nullptr));
        for(int n = 0; n < number; n++)
        {
            strcGame.ImmuneRow = rand()% strcGame.Rows;
            strcGame.ImmuneCol = rand()% strcGame.Columns;

            while(strcGame.M_Array[strcGame.ImmuneRow][strcGame.ImmuneCol] != empty_space)
            {
                strcGame.ImmuneRow = rand()% strcGame.Rows;
                strcGame.ImmuneCol = rand()% strcGame.Columns;
            }
            strcGame.M_Array[strcGame.ImmuneRow][strcGame.ImmuneCol] = intFeaturee;
        }
    }

    // This function will place my recovered characters in th world
    void place_Recovered(Gamess& strcGame, int count_numb, int intFeatur, int& Rows, int& Columns)
    {
        for(int i = 0; i < count_numb; i++)
        {
            strcGame.RcoveredRow = rand()% strcGame.Rows;
            strcGame.RcoveredCol = rand()% strcGame.Columns;

            while(strcGame.M_Array[strcGame.RcoveredRow][strcGame.RcoveredCol] != empty_space)
            {
                strcGame.RcoveredRow = rand()% strcGame.Rows;
                strcGame.RcoveredCol = rand()% strcGame.Columns;
            }
            strcGame.M_Array[strcGame.RcoveredRow][strcGame.RcoveredCol] = intFeatur;
        }
    }





     void printing_world(Gamess strcGame)
     {
         assert(strcGame.M_Array != nullptr);
         system("cls");

         for(int i = 0; i < strcGame.Rows; i++)
         {
             for(int n = 0; n < strcGame.Columns; n++)
             {
                 cout << Features[strcGame.M_Array[i][n]] << " ";
             }
             cout << endl;
         }
         cout << "Statistics before simulation\n" << endl;
         cout << "Infected people: " << strcGame.infected_people << endl;
         cout << "Immune people: " << strcGame.ImmunePeople << endl;
         cout << "Recovered people: " << strcGame.RecoveredPeople << endl;
         cout << "\nMenu selection" << endl;
         cout << "a). Simulate" << endl;
         cout << "b). End simulation" << endl;
    }

    bool is_in_World(int Rows, int Columns, int intRows, int intCols)
    {
        return(intRows >= 0 && intRows < Rows && intCols >= 0 && intCols < Columns);
    }

    // This function will move the infected ones
    void Move_infected(Gamess& strcGame, int recovery_chance, int immunity_chances, int infect)
    {
        assert(strcGame.M_Array != nullptr);
        bool we_move = true;
        do
        {
            we_move = true;

        for(int row = 0; row < strcGame.Rows; row++)
        {
            for( int col = 0; col < strcGame.Columns; col++)
            {
                if(strcGame.M_Array[row][col] == Infected)
                {

        int Drow = strcGame.InfectedRow;
        int Dcol = strcGame.InfectedCol;

        int Rand_Move = Random_Generator(1,8);

        switch(Rand_Move)
        {
        case 1:
            //move up
            Drow--;
            break;
        case 2:
            //move down
            Drow++;
            break;
        case 3:
            //move left
            Dcol--;
            break;
        case 4:
            //move right
            Dcol++;
            break;
        case 5:
            //move up left
            Drow--;
            Dcol--;
            break;
        case 6:
            //move up right
            Drow--;
            Dcol++;
            break;
        case 7:
            //move down left
            Drow++;
            Dcol--;
            break;
        case 8:
            // moove down right
            Drow++;
            Dcol++;
            break;
        }

        // I am testing if i am still in the world

        if(is_in_World(strcGame.Rows, strcGame.Columns, Drow, Dcol))
        {
            int Dfeature = strcGame.M_Array[Drow][Dcol];

            if(Dfeature == empty_space)
            {
                strcGame.M_Array[Drow][Dcol] = Infected;
                strcGame.M_Array[strcGame.InfectedRow][strcGame.InfectedCol] = empty_space;

                //handling the infection through the infectious range
                Infectious_Range(strcGame, infect);

                // for each movement i handle the chance that the infected might heal
                if(Random_Generator(0,100) <= recovery_chance)
                {
                    strcGame.M_Array[Drow][Dcol] = Recovered;
                    strcGame.Recovered_count++;

                    // if the infected recovers, there is a chance that it becomes immune
                    if(Random_Generator(0,100) <= immunity_chances)
                    {
                        strcGame.M_Array[Drow][Dcol] = Immune;
                        strcGame.Immune_count++;
                    }

                    // if the infected recovers but does not become immune
                    if(!(Random_Generator(0,100) <= immunity_chances))
                    {
                        strcGame.M_Array[Drow][Dcol] = Recovered;
                        strcGame.Recovered_count++;
                    }
                }
            }
            else if(Dfeature == Infected || Dfeature != empty_space)
            {
                return;
            }
        }
        else
        {
            cout << "You are out of the world" << endl;
            return;
        }
        strcGame.M_Array[row][col] = empty_space;
        strcGame.M_Array[Drow][Dcol] = Infected;
                }
            }
        }

        }
        while(we_move);
    }


    // This function will move the immune characters
    void Move_immune(Gamess& strcGame)
    {
        assert(strcGame.M_Array != nullptr);
        bool moved = false;
        do
        {
            moved = false;
        for( int b = 0; b < strcGame.Rows; b++)
        {
            for(int c = 0; c < strcGame.Columns; c++)
            {
                if(strcGame.M_Array[b][c] == Immune)
                {

        int intDrow = strcGame.ImmuneRow;
        int intDcol = strcGame.ImmuneCol;

        int rand_Cell = Random_Generator(1,8);

        switch(rand_Cell)
        {
        case 1:
            // move up
            intDrow--;
            break;
        case 2:
            // move down
            intDrow++;
            break;
        case 3:
            // move left
            intDcol--;
            break;
        case 4:
            // move right
            intDcol++;
            break;
        case 5:
            // move up left
            intDrow--;
            intDcol--;
            break;
        case 6:
            // move up right
            intDrow--;
            intDcol++;
            break;
        case 7:
            // move down left
            intDrow++;
            intDcol--;
            break;
        case 8:
            // move down right
            intDrow++;
            intDcol++;
            break;
        }

        // testing if we are still in the world
        if(is_in_World(strcGame.Rows, strcGame.Columns, intDrow, intDcol))
        {
            int thFeature = strcGame.M_Array[intDrow][intDcol];

            if(thFeature == empty_space)
            {
                strcGame.M_Array[intDrow][intDcol] = Immune;
                strcGame.M_Array[strcGame.ImmuneRow][strcGame.ImmuneCol] = empty_space;
            }
            else if(thFeature != empty_space)
            {
                return;
            }
        }
        else
        {
            cout << "Out of world" << endl;
            return;
        }

        strcGame.M_Array[b][c] = empty_space;
        strcGame.M_Array[intDrow][intDcol] = Immune;
                }
            }
        }
        }
        while(moved);
    }

    // this function will handle the movement for the recovered characters
    void Move_recovered(Gamess& strcGame)
    {
        assert(strcGame.M_Array != nullptr);
        bool moving = true;
        do
        {
            moving = true;

        for(int e = 0; e < strcGame.Rows; e++)
        {
            for(int f = 0; f < strcGame.Columns; f++)
            {
                if(strcGame.M_Array[e][f] == Recovered)
                {

        int inDrow = strcGame.RcoveredRow;
        int inDcol = strcGame.RcoveredCol;

        int rand_space = Random_Generator(1,8);

        switch(rand_space)
        {
        case 1:
            // move up
            inDrow--;
            break;
        case 2:
            // move down
            inDrow++;
            break;
        case 3:
            // move left
            inDcol--;
            break;
        case 4:
            // move right
            inDcol++;
            break;
        case 5:
            // move up left
            inDrow--;
            inDcol--;
            break;
        case 6:
            // move up right
            inDrow--;
            inDcol++;
            break;
        case 7:
            // move down left
            inDrow++;
            inDcol--;
            break;
        case 8:
            // move down right
            inDrow++;
            inDcol++;
            break;
        }

        // testing if we are still in world
        if(is_in_World(strcGame.Rows, strcGame.Columns, inDrow, inDcol))
        {
            int the_featur = strcGame.M_Array[inDrow][inDcol];

            if(the_featur == empty_space)
            {
                strcGame.M_Array[inDrow][inDcol] = Recovered;
                strcGame.M_Array[strcGame.RcoveredRow][strcGame.RcoveredCol] = empty_space;

            }
            else if(the_featur != empty_space)
            {
                return;
            }
        }
        else
        {
            cout << "Out of world" << endl;
            return;
        }
        strcGame.M_Array[e][f] = empty_space;
        strcGame.M_Array[inDrow][inDcol] = Recovered;
                }
            }
        }

        }
        while(moving);
    }


    //This function will scan the range that if a person who is immune or recovered  if within that range , they can get infected
    void Infectious_Range(Gamess& strcGame, int infect_rate)
    {
        assert(strcGame.M_Array != nullptr);

        for(int r = strcGame.InfectedRow-1; r <= strcGame.InfectedRow+1; r++)
        {
            for(int c = strcGame.InfectedCol-1; c <= strcGame.InfectedCol+1; c++)
            {
                // skip the player`s own cell
                if( r == strcGame.InfectedRow && c == strcGame.InfectedCol)
                {
                    continue;
                }
                // skip a cell that is more than 1 squere radius
                if(abs(r - strcGame.InfectedRow) + abs(c - strcGame.InfectedCol) > 1)
                {
                    continue;
                }
                // scanns if other characters are within the infectious range of 1 squere radious
                if(abs(r - strcGame.InfectedRow) + abs(c - strcGame.InfectedCol) <= 1)
                {
                    if(is_in_World(strcGame.Rows, strcGame.Columns, r, c))
                    {
                        // if the immune character is within the range, it can be infected
                        if(strcGame.M_Array[r][c] == Immune)
                        {
                            if(Random_Generator(0,100) <= infect_rate)
                            {
                                strcGame.M_Array[r][c] = Infected;
                                strcGame.Infected_count++;
                            }
                        }
                        // if the recovered character is within the range, it can be infected
                        if(strcGame.M_Array[r][c] == Recovered)
                        {
                            if(Random_Generator(0,100) <= infect_rate)
                            {
                                strcGame.M_Array[r][c] = Infected;
                                strcGame.Infected_count++;
                            }
                        }
                    }
                }
            }
        }
    }




}
