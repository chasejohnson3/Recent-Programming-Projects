#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line_of_grid;
    string array_of_lines[9];
    int line_number(0);
    ifstream grid("Sudoku Grid 01.txt");
    if (grid.fail())
    {
        cerr << "Unable to open Sudoku Grid 01." << endl;
        return 0;
    }
    grid >> line_of_grid;
    array_of_lines[line_number] = line_of_grid;
    line_number++;
    while (!grid.eof())
    {
        grid >> line_of_grid;
        array_of_lines[line_number] = line_of_grid;
        line_number++;
    }
    for(int i=0; i<9; i++)
    {
        cout << array_of_lines[i] << endl;
    }
    return 0;
}
