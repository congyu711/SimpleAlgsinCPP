#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int flag = 0;
    int nin[9][9] = {
        {1, 1, 1, 2, 2, 2, 3, 3, 3},
        {1, 1, 1, 2, 2, 2, 3, 3, 3},
        {1, 1, 1, 2, 2, 2, 3, 3, 3},
        {4, 4, 4, 5, 5, 5, 6, 6, 6},
        {4, 4, 4, 5, 5, 5, 6, 6, 6},
        {4, 4, 4, 5, 5, 5, 6, 6, 6},
        {7, 7, 7, 8, 8, 8, 9, 9, 9},
        {7, 7, 7, 8, 8, 8, 9, 9, 9},
        {7, 7, 7, 8, 8, 8, 9, 9, 9}};
    bool check(int i, int j, int k, vector<vector<char>> &board)
    {
        for (int ii = 0; ii < 9; ii++)
        {
            if (board[i][ii] == static_cast<char>('0' + k) ||
                board[ii][j] == static_cast<char>('0' + k))
                return 0;
        }
        for (int ii = 0; ii < 9; ii++)
        {
            for (int jj = 0; jj < 9; jj++)
            {
                if (nin[ii][jj] == nin[i][j] && board[ii][jj] == static_cast<char>('0' + k))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if(flag==1)
            return ;
        if (i == 9)
        {
            flag = 1;
            // for (auto e : board)
            // {
            //     for (auto i : e)
            //         cout << i;
            //     cout << endl;
            // }
            return;
        }
        if (board[i][j] != '.')
        {
            if (j == 8)
                dfs(i + 1, 0, board);
            else
                dfs(i, j + 1, board);
        }
        else
        {
            for (int k = 1; k <= 9; k++)
            {
                if (check(i, j, k, board))
                {
                    board[i][j] = static_cast<char>('0' + k);
                    if (j == 8)
                        dfs(i + 1, 0, board);
                    else
                        dfs(i, j + 1, board);
                    if(!flag)
                        board[i][j] = '.';
                }
            }

            // for (auto e : board)
            // {
            //     for (auto i : e)
            //         cout << i;
            //     cout << endl;
            // }
            // cout << endl;
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        dfs(0, 0, board);
    }
};
int main()
{
    Solution a;
    vector<vector<char>> arr =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    a.solveSudoku(arr);
    for (auto e : arr)
    {
        for (auto i : e)
            cout << i;
        cout << endl;
    }
}