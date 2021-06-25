//https://codeforces.com/contest/1517/problem/B
#include <bits/stdc++.h>
using namespace std;
int tr[110][110];
bool check[110][110];
void solve()
{
    memset(tr, 0, sizeof(tr));
    memset(check, 0, sizeof(check));
    vector<pair<int, int>> arr;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tr[i][j];
            arr.push_back(make_pair(tr[i][j], i * m + j));
        }
    sort(arr.begin(), arr.end());
    vector<int> col[110];
    for (int i = 0; i < m; i++)
    {
        int a = arr[i].second / m, b = arr[i].second % m;
        col[b].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        while (col[i].size() > 1)
        {
            int c = col[i].back();
            col[i].pop_back();
            for (int j = 0; j < m; j++)
            {
                if (col[j].size() == 0)
                {
                    int a = arr[c].second / m, b = arr[c].second % m;
                    swap(tr[a][b],tr[a][j]);
                    col[j].push_back(c);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << tr[i][j] << ' ';
        cout << endl;
    }
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
