//https://codeforces.com/contest/1517/problem/E
#include <bits/stdc++.h>
#define whatis(x) cout << #x << ' ' << x << endl
#define what cout << i <<' '<<len<< ' ' << sumc << ' ' << sump << endl
using namespace std;
const int mod = 998244353;
int t;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<long long int> prefixsum(n + 1, 0);
    vector<long long int> _sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        prefixsum[i] = prefixsum[i - 1] + arr[i];
        if (i == 1)
            _sum[i] = arr[i];
        else
            _sum[i] = _sum[i - 2] + arr[i];
    }
    //p...p
    long long int ans = 0;
    //solving the first case : pppcccc&cccppp
    for (int i = 1; i <= n; i++)
        if (2 * prefixsum[i] != prefixsum[n])
            ans++;
    ans %= mod;

    whatis(ans);
    //solving the second case : (c/p)cc...c  pcpc...pc  p...p(c/p)
    //c xxx p
    for (int i = 0; i <= n - 2; i++)
    {
        int sumc = prefixsum[i];
        int sump = prefixsum[n] - prefixsum[i];
        if (sumc >= sump)
            break;
        int len = 2;
        for (; i + len <= n; len += 2)
        {
            sumc = prefixsum[i] + _sum[i + len] - _sum[i];
            if (i == 0)
                sump = prefixsum[n] - prefixsum[i + len] + _sum[i + len - 1];
            else
                sump = prefixsum[n] - prefixsum[i + len] + _sum[i + len - 1] - _sum[i - 1];

            if (sumc >= sump)
                break;
        }
        ans += max(0, (len - 2)/2);
        ans %= mod;
    }
    whatis(ans);
    //p (ccc) pc..pc (ppp)p
    for (int i = 1; i <= n - 3; i++)
    {
        int sumc = prefixsum[i] - prefixsum[1];
        int sump = prefixsum[n] - prefixsum[i] + prefixsum[1];
        if (sumc >= sump)
            break;
        int len = 2;
        for (; i + len < n; len += 2)
        {
            sumc = prefixsum[i] - prefixsum[1] + _sum[i + len] - _sum[i];
            sump = prefixsum[n] - prefixsum[i + len] + _sum[i + len - 1] - _sum[i - 1];
            if (sumc >= sump)
                break;
        }
        ans += max(0, (len - 2)/2);
        ans %= mod;
    }
    whatis(ans);
    // cccc pc...pc (pppp)c
    for (int i = 1; i < n; i++)
    {
        int sumc = prefixsum[i] + arr[n];
        int sump = prefixsum[n - 1] - prefixsum[i];
        if (sumc >= sump)
            break;
        int len = 2;
        for (; i + len < n; len += 2)
        {
            sumc = arr[n] + prefixsum[i] + _sum[i + len] - _sum[i];
            sump = prefixsum[n - 1] - prefixsum[i + len] + _sum[i + len - 1] - _sum[i - 1];
            if (sumc >= sump)
                break;
        }
        ans += max(0, (len - 2)/2);
        ans %= mod;
    }
    whatis(ans);
    // p(ccc) pc...pc (pppp)c
    for (int i = 1; i <= n - 3; i++)
    {
        int sumc = prefixsum[i] - prefixsum[1] + arr[n];
        int sump = prefixsum[n - 1] - prefixsum[i] + arr[1];
        if (sumc >= sump)
            break;
        int len = 2;
        for (; i + len < n; len += 2)
        {
            sumc = arr[n] + prefixsum[i] - prefixsum[1] + _sum[i + len] - _sum[i];
            sump = arr[1] + prefixsum[n - 1] - prefixsum[i + len] + _sum[i + len - 1] - _sum[i - 1];
            if (sumc >= sump)
                break;
        }
        ans += max(0, (len - 2)/2);
        ans %= mod;
    }
    cout << ans % mod << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cin >> t;
    // while (t--)
    solve();
}
