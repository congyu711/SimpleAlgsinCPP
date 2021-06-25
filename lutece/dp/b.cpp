#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
LL cost[2222][2222];
LL n;
LL dp[2222][2222];
int main()
{
    memset(dp, 7, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (j != n)
                cost[j][i] = cost[i][j];
        }
    LL ans = inf;
    dp[1][1]=0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j < i - 1)
            {
                //必然经过 i-1
                dp[i][j] = dp[i - 1][j] + cost[i - 1][i];
                // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
            else
            {
                dp[i][j] = inf;
                for (int k = 1; k <= j; k++)
                {
                    //dp[k][j]=dp[j][k];
                    dp[i][j] = min(dp[i][j], dp[j][k] + cost[k][i]);
                }
                // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
    }
    for (int j = 1; j < n; j++)
        ans = min(ans, dp[n][j]);
    cout << ans << endl;
}