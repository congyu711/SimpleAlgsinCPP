//
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int t;
long long quickmod(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout<<quickmod(n,k,mod)<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
        solve();
}
