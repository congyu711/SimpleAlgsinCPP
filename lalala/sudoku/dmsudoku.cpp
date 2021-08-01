#include <iostream>
#include <set>
#include <fstream>
#include <vector>
using namespace std;

class sudoku
{
private:
    vector<set<int>> arr[9][9];

public:
    friend ifstream &operator>>(ifstream &in, sudoku &su1)
    {
        int c;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                in >> c;
                set<int> sa;
                su1.arr[i][j].push_back(sa);
                if(c!=0)
                    su1.arr[i][j][0].insert(c);
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
                if (arr[i][j][0].empty())
                    cout << 0 << ' ';
                else
                    cout << *arr[i][j][0].begin() << ' ';
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