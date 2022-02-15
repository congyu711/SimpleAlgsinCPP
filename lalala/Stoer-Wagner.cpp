//oi-wiki.
#include <bits/stdc++.h>
using namespace std;
const int N = 601;
int edge[N][N];

int dist[N], vis[N], bin[N];
int n, m;

int contract(int &s, int &t)
{ // Find s,t cut
    memset(dist, 0, sizeof(dist));
    memset(vis, false, sizeof(vis));
    int i, j, k, mincut, maxc;
    for (i = 1; i <= n; i++)
    {
        k = -1;
        maxc = -1;
        for (j = 1; j <= n; j++)
            if (!bin[j] && !vis[j] && dist[j] > maxc)
            {
                k = j;
                maxc = dist[j];
            }
        if (k == -1)
            return mincut;
        s = t;
        t = k;
        mincut = maxc;
        vis[k] = true;
        for (j = 1; j <= n; j++)
            if (!bin[j] && !vis[j])
                dist[j] += edge[k][j];
    }
    return mincut;
}

const int inf = 0x3f3f3f3f;

int Stoer_Wagner()
{
    int mincut, i, j, s, t, ans;
    for (mincut = inf, i = 1; i < n; i++)
    {
        ans = contract(s, t);
        bin[t] = true;
        if (mincut > ans)
            mincut = ans;
        if (mincut == 0)
            return 0;
        for (j = 1; j <= n; j++)
            if (!bin[j])
                edge[s][j] = (edge[j][s] += edge[j][t]);
    }
    return mincut;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        edge[u][v] += w, edge[v][u] += w;
    }
    cout << Stoer_Wagner();
    return 0;
}