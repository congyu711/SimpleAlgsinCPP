//建图tle

#include <bits/stdc++.h>
using namespace std;
// int use[250010];
int dis[250010], n, m, x, y, z, s;
vector<pair<int, int>> vec[250010];
queue<pair<int, int>> pq;
void add(int x, int y, int z)
{
    vec[x].push_back(make_pair(y, z));
}
void dij(int s)
{
    memset(dis, 63, sizeof(dis));
    dis[s] = 0;
    pq.push(make_pair(-dis[s], s));
    while (pq.size())
    {
        int u = pq.front().second;
        pq.pop();
        // if(use[u])
        //     continue;
        // use[u]=1;
        for (int i = 0; i < vec[u].size(); i++)
            if (dis[vec[u][i].first] > dis[u] + vec[u][i].second)
            {
                dis[vec[u][i].first] = dis[u] + vec[u][i].second;
                pq.push(make_pair(-dis[vec[u][i].first], vec[u][i].first));
            }
    }
}
int main()
{
    int r, c;
    cin >> r >> c;
    int tmp;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c - 1; j++)
        {
            cin >> tmp;
            add(r * (i) + j, (i)*r + j + 1, tmp);
            add((i)*r + j + 1, r * (i) + j, tmp);
        }
    }
    for (int i = 0; i < r - 1; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> tmp;
            add(r * (i) + j, r * (i + 1) + j, tmp);
            for (int k = i + 1; k < r; k++)
            {
                add(r * (k) + j, r * (i) + j, k - i + 1);
            }
        }
    }
    dij(0);
    cout << dis[r * c - 1] << ' ';
    puts("");
}