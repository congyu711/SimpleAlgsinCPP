#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <array>
using namespace std;

class sudoku
{
private:
    array<array<int,9>,9> arr;

public:
    friend ifstream &operator>>(ifstream &in, sudoku &su1)
    {
        int c;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                in>>su1.arr[i][j];
            }
        }
        return in;
    }

    void print()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout<<arr[i][j]<<' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    sudoku su1;
    ifstream infile;
    infile.open("sudoku1.in");
    infile >> su1;
    su1.print();
}