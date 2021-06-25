#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;

void solve()
{
    LL n, m;
    cin >> n >> m;
    LL a = sqrt(n), b = sqrt(m);
    cout << a * b << endl;
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