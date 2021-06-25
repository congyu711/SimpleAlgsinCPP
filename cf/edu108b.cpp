//
#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
void solve()
{
    memset(dp, 0, sizeof(dp));
    int n, m, k;
    cin >> n >> m >> k;
    long long ans = (n - 1) + n * (m - 1);
    if (ans == k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
