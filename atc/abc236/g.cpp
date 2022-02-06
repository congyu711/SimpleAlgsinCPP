#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, t, l, a, b, c;

const int inf = 0x3f3f3f3f;
vector<vector<int>> adj(111, vector<int>(111, inf));

vector<vector<int>> mul(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
    vector<vector<int>> res(111, vector<int>(111, inf));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                res[i][j] = min(res[i][j], max(a[i][k], b[k][j]));
            }
        }
    }
    return res;
}
vector<vector<int>> binpow(vector<vector<int>> &a, int k)
{
    vector<vector<int>> res(111, vector<int>(111, inf));
    for (int i = 1; i <= n; i++)
        res[i][i] = -1;
    while (k)
    {
        if (k & 1)
            res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //         cout << res[i][j] << ' ';
        //     cout << endl;
        // }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t >> l;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        adj[a][b] = i;
        // adj[a].push_back(make_pair(b,t));
    }
    vector<int> dp(111, inf), ans(111, inf);
    dp[1] = 0;
    auto tmp = binpow(adj, l);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            ans[i] = min(ans[i], max(dp[j], tmp[j][i]));
    }
    for (int i = 1; i <= n; i++)
        cout << (ans[i]==inf?-1:ans[i]) << ' ';
}