#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1)
                {
                    int cnt = 0;
                    for (int a = i - 1; a <= i + 1; a++)
                    {
                        for (int b = j - 1; b <= j + 1; b++)
                        {
                            if (a >= n || a < 0 || b >= m || b < 0 || (a == i && b == j))
                                continue;
                            else
                            {
                                if (board[a][b] == 1)
                                    cnt++;
                            }
                        }
                    }
                    if (cnt < 2 || cnt > 3)
                        ans[i][j] = 0;
                    else
                        ans[i][j] = 1;
                }
                else
                {
                    int cnt = 0;
                    for (int a = i - 1; a <= i + 1; a++)
                    {
                        for (int b = j - 1; b <= j + 1; b++)
                        {
                            if (a >= n || a < 0 || b >= m || b < 0)
                                continue;
                            else
                            {
                                if (board[a][b] == 1)
                                    cnt++;
                            }
                        }
                    }
                    if (cnt == 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = ans[i][j];
    }
};
int main()
{
    
}