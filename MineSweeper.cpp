/*******************************************************************************
 * Minesweeper Project
 * project by Elijah Baptiste
/******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{

    int dif;
    int dim = 10;
    string choice;
    string one = "easy";
    string two = "medium";
    string three = "hard";
    // array of data for the board. Will hold the data for where the bombs are.
    int MSdata[9][9];

    // Numbeer of bombs on the board
    // int bombs = dif;

    // Difficulty selection. Allows users to choose between easy, medium, and hard. This affects the total size of the grid and number of bombs

    cout << "Hello and Welcome to this Game of Minesweeper" << endl;
    cout << "What difficulty game would you like to Start? (easy, medium, hard)" << endl;
    cin >> choice;

    if (choice == one)
    {
        dif = 9;
    }
    else if (choice == two)
    {
        dif = 36;

    }
    else if (choice == three)
    {
        dif = 64;

    }
    else
    {
        dif = 25;
    }

    // function to randomly assing the locations of the bombs
    for (int z = 0; z < sqrt(dif); z++)
    {
        for (int y = 0; y < sqrt(dif); y++)
        {
            int a = rand() % dim;
            int b = rand() % dim;
            if (MSdata[a][b] != 9)
            {
                MSdata[a][b] = 9;
            }
        }
    }

    // Function to iterate through the grid and fill the non bomb squares with their corresponding numbers.
    for (int x = 0; x < dim; x++)
    {
        for (int v = 0; v < dim; v++)
        {
            if (MSdata[x][v] != 9)
            {
                int m = 0;
                for (int j = (x - 1); j <= (x + 1); j++)
                {
                    for (int k = (v - 1); k <= (v + 1); k++)
                    {
                        if (j >= 0 && j <= dim)
                        {
                            if (k >= 0 && k <= dim)
                            {
                                if (MSdata[j][k] == 9)
                                {
                                    m++;
                                }
                            }
                        }
                    }
                    MSdata[x][v] = m;
                }
            }
        }
    }

    for (int x = 0; x < dim; x++)
    {
        cout << "|";
        for (int v = 0; v < dim; v++)
        {
            cout << MSdata[x][v] << " ";
        }
        cout << "|" << endl;
        cout << "|";
        for (int b = 0; b < dim; b++)
        {
            cout << "__";
        }
        cout << "|" << endl;
    }

    //5 Minute Timer
  
      cout << "5 Minute Timer Starting!";
        _sleep(500);
        cout << endl;

    for(int a =5; 5 >=0; a--){
        int i = 0;
        for(int b = 5; b >= 0; b--){ 
            for(int c = 9; c >= 0; c--){
                if( i == 31 || i == 59){
                    cout << "0" << a << ":" << b << c<< endl;
                }

               _sleep(1000);
               i++;
            }

        }
    }
    return 0;
}