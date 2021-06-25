#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;

int t, n, tmp, cnt;

void solve()
{
    int minn=0x7fffffff;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        minn = min(tmp, minn);
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == minn)
            cnt++;
        if ((arr[i] & minn) != minn)
        {
            cout << 0 << endl;
            return;
        }
    }
    if (cnt < 2)
    {
        cout << 0 << endl;
        return;
    }
    long long int ans = 1;
    for (int i = 1; i <= n - 2; i++)
    {
        ans *= (1ll*i);
        ans = ans % m;
    }
    ans *= cnt;
    ans %= m;
    ans *= (cnt - 1);
    ans %= m;
    cout << ans << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        solve();
    }
}