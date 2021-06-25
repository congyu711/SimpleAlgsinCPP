//https://codeforces.com/contest/1519/problem/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &e : a)
        cin >> e;
    for (auto &e : b)
        cin >> e;
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i] * b[i];
    ll ans = pre[n];
    for (int mid = 0; mid < n; mid++)
    {
        //odd
        ll res = a[mid] * b[mid];
        for (int l = mid - 1, r = mid + 1; l >= 0 && r < n; l--, r++)
        {
            res += a[r] * b[l];
            res += a[l] * b[r];
            ans = max(ans, res + pre[l] + pre[n] - pre[r + 1]);
        }
        res = 0;
        for (int l = mid , r = mid + 1; l >= 0 && r < n; l--, r++)
        {
            res += a[r] * b[l];
            res += a[l] * b[r];
            ans = max(ans, res + pre[l] + pre[n] - pre[r + 1]);
        }
    }
    cout << ans << endl;
}
