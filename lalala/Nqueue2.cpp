#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool col[10], diag[10 * 2], diag2[10 * 2];
    int ans[10];
    int cnt = 0;
    void dfs(int i, int n)
    {
        if (i == n)
        {
            cnt++;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (!col[j] && !diag[i + j] && !diag2[n - j + i])
            {
                //cout << "----------" << j << endl;
                ans[i] = j;
                col[j] = 1;
                diag[i + j] = 1;
                diag2[n - j + i] = 1;
                dfs(i + 1, n);
                ans[i] = -1;
                col[j] = 0;
                diag[i + j] = 0;
                diag2[n - j + i] = 0;
            }
        }
        return;
    }
    int solveNQueens(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        cnt =0;
        memset(col, 0, sizeof(col)), memset(diag, 0, sizeof(diag)), memset(diag2, 0, sizeof(diag2));
        memset(ans, -1, sizeof(ans));
        dfs(0, n);

        return cnt;
    }
};
int main()
{
    Solution a;
    for (int i = 1; i < 11; i++)
    {
        int ans = a.solveNQueens(i);
        cout << ans << endl;
    }
}