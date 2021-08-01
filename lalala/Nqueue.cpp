#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool col[10], diag[10 * 2], diag2[10 * 2];
    int ans[10];
    bool findans = 0;
    void buildboard(vector<vector<string>> &arr, int n)
    {
        vector<string> vec(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            vec[i][ans[i]] = 'Q';
        arr.push_back(vec);
    }
    void dfs(vector<vector<string>> &arr, int i, int n)
    {
        if (i == n)
        {
            buildboard(arr, n);
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
                dfs(arr, i + 1, n);
                ans[i] = -1;
                col[j] = 0;
                diag[i + j] = 0;
                diag2[n - j + i] = 0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> arr(n, vector<string>(n, string(n, '.')));
        if(n==1)
        {
            vector<vector<string>> arr(1, vector<string>(1, string(1, 'Q')));
            return arr;
        }
        memset(col, 0, sizeof(col)), memset(diag, 0, sizeof(diag)), memset(diag2, 0, sizeof(diag2));
        memset(ans, -1, sizeof(ans));
        dfs(arr, 0, n);
        auto it=arr.begin()+n;
        arr.erase(arr.begin(),it);
        return arr;
    }
};
int main()
{
    Solution a;
    vector<vector<string>> ans = a.solveNQueens(1);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
}