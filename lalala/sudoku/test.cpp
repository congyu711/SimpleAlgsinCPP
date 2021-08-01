//quzhan sudoku

#include <bits/stdc++.h>
using namespace std;
int a[15][15], jiu[15][15];
int tot;
void make_jiu()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            if (i <= 3 && j <= 3)
                jiu[i][j] = 1;
            if (i > 3 && i <= 6 && j <= 3)
                jiu[i][j] = 2;
            if (i > 6 && j <= 3)
                jiu[i][j] = 3;
            if (i <= 3 && j > 3 && j <= 6)
                jiu[i][j] = 4;
            if (i > 3 && i <= 6 && j > 3 && j <= 6)
                jiu[i][j] = 5;
            if (i > 6 && j > 3 && j <= 6)
                jiu[i][j] = 6;
            if (i <= 3 && j > 6)
                jiu[i][j] = 7;
            if (i > 3 && i <= 6 && j > 6)
                jiu[i][j] = 8;
            if (i > 6 && j > 6)
                jiu[i][j] = 9;
        }
}
int can(int x, int y, int num)
{
    for (int i = 1; i <= 9; i++)
        if (a[x][i] == num || a[i][y] == num)
            return 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            if (jiu[i][j] == jiu[x][y])
                if (a[i][j] == num)
                    return 0;
    return 1;
}
void dfs(int x, int y)
{
    if (x == 10)
    {
        cout << endl
             << "��" << ++tot << "������" << endl;
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
        return;
    }
    if (a[x][y])
    {
        if (y == 9)
            dfs(x + 1, 1);
        else
            dfs(x, y + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (can(x, y, i))
            {
                a[x][y] = i;

                if (y == 9)
                    dfs(x + 1, 1);
                else
                    dfs(x, y + 1);
                a[x][y] = 0;
            }
        }
        return;
    }
}
int main()
{
    ifstream infile;
    infile.open("sudoku1.in");
    make_jiu();
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            infile >> a[i][j];
    dfs(1, 1);
    cout << endl
         << "����" << tot << "���⡣" << endl;
}
