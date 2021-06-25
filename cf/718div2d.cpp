//https://codeforces.com/contest/1517/problem/D
#include <bits/stdc++.h>
using namespace std;

//vector<pair<int,int> > vec[250002];
int r[510][510], d[510][510];
int dp[510][510][22];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    int c;
    cin >> n >> m >> k;
    int sz1 = (m - 1) * n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < m; j++)
            cin >> r[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];
    if (k & 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << -1 << ' ';
            cout << endl;
        }
        return 0;
    }
    for (int a = 1; a <= k; a++)
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j][a] = 0x7fffffff;
                if (i != 1)
                    dp[i][j][a] = min(dp[i][j][a], dp[i - 1][j][a - 1] + d[i - 1][j]);
                if (i != n)
                    dp[i][j][a] = min(dp[i][j][a], dp[i + 1][j][a - 1] + d[i][j]);
                if (j != 1)
                    dp[i][j][a] = min(dp[i][j][a], dp[i][j - 1][a - 1] + r[i][j - 1]);
                if (j != m)
                    dp[i][j][a] = min(dp[i][j][a], dp[i][j + 1][a - 1] + r[i][j]);
            }
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << dp[i][j][k / 2] * 2 << ' ';
        cout << endl;
    }

}
