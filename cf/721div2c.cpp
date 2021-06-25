//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int N = 1e5 + 10;

void solve()
{
    ll ans = 0;
    ll dp[N];
    int arr[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(arr[i]) && i > 1)
            dp[i] = dp[i - 1] + mp[arr[i]];
        else if (i > 1)
            dp[i] = dp[i - 1];
        mp[arr[i]] += i;
        ans += dp[i];
    }
    cout << ans << endl;
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
