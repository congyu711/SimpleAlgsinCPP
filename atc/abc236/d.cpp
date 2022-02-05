#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[20][20];
int n;
int l[20];
int ans;
unordered_map<string, int> mp;
void getcom(int nn, int m)
{
    if (m == 0)
    {
        bool f[20] = {0};
        string ss;
        for (int i = 1; i <= n; i++)
            f[l[i]] = 1;
        for (int i = 1; i <= 2 * n; i++)
            if (!f[i])
                ss.push_back('0' + i);
        // sort(l+1,l+n+1);
        if (mp[ss] != 0)
        {
            return;
        }
        do
        {
            int tmp = 0;
            for (int i = 1; i <= n; i++)
                tmp ^= a[l[i]][int(ss[i-1]-'0')];
            ans = max(ans, tmp);
            string str;
            for (int i = 1; i <= n; i++)
                str.push_back('0' + l[i]);
            mp[str]++;
        } while (next_permutation(l + 1, l + n + 1));
        // for(int i=1;i<=n;i++)   cout<<l[i]<<' ';cout<<endl;
        return;
    }
    for (int i = nn; i >= m; i--)
    {
        l[m] = i;
        getcom(i - 1, m - 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < 2 * n; i++)
    {
        for (int j = i + 1; j <= 2 * n; j++)
        {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    getcom(2 * n, n);
    cout << ans << endl;
}