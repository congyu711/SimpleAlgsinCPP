#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //uniquepaths2
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        const int n = obstacleGrid.size();
        const int m = obstacleGrid[0].size();
        vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));
        ans[1][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (obstacleGrid[i - 1][j - 1] == 1)
                    ans[i][j] = 0;
                else
                {
                    if (!ans[i][j])
                        ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
                }
            }
        }
        return ans[n][m];
    }

    //uniquepath3 1 start,2 end, -1 obstacle && pass all blocks
    int ans = 0;
    int n, m;
    int dfs(int i, int j, int ss, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1)
            return 0;
        else if (grid[i][j] == 2)
            return ss == 0 ? 1 : 0;
        else
        {
            grid[i][j] = -1;
            int sum = dfs(i + 1, j, ss - 1, grid) + dfs(i, j + 1, ss - 1, grid) + dfs(i - 1, j, ss - 1, grid) + dfs(i, j - 1, ss - 1, grid);
            grid[i][j] = 0;
            return sum;
        }
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int r, c, step = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                {
                    r = i, c = j;
                }
                else if (grid[i][j] == 0)
                    step++;
        return dfs(r, c, step, grid);
    }
};
int main()
{
    Solution a;
    vector<vector<int>> arr = {{1, 0, 0}, {0, 2, 0}};
    vector<vector<int>> arr1 = {{1, -1}, {0, 2}};
    cout << a.uniquePathsIII(arr1) << endl;
}