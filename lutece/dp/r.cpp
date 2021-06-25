#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5010;
const int mod = 1e9 + 7;
int w[N];
LL dp[N];
LL tmp[N];
LL ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    LL res = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] += dp[j - w[i]];
            dp[j] %= mod;
            tmp[j] = dp[j];
        }
    }
    // for(int i=0;i<=m;i++)   cout<<i<<' '<<dp[i]<<endl;
    for (int i = n; i >= 1; i--)
    {
        for (int j = w[i]; j <= m; j++)
        {
            dp[j] -= dp[j - w[i]];
            dp[j] +=mod;
            dp[j] %= mod;
        }
        for(int j=1;j<=m;j++)   res^=dp[j];
        // cout << "miss" << i << endl;
        // for (int i = 0; i <= m; i++)
        //     cout << i << ' ' << dp[i] << endl;
        // cout << endl;

        for (int j = w[i]; j <= m; j++)
            dp[j] = tmp[j];
    }
    cout << res << endl;
}
/*
3 2
1 1 2

*/