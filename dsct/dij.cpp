#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int use[N], dis[N], n, m, x, y, z, S;
vector<pair<int, int>> vec[N];
priority_queue<pair<int, int>> pq;
void add(int x, int y, int z)
{
    vec[x].push_back(make_pair(y, z));
}
void dij(int S)
{
    memset(use, 0, sizeof(use));
    memset(dis, 63, sizeof(dis));
    dis[S] = 0;
    pq.push(make_pair(-dis[S], S));
    while (pq.size())
    {
        int u = pq.top().second;
        pq.pop();

        if (use[u])
            continue;
        use[u] = 1;
        //如果u\in U 跳过
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
    cin >> n >> m >> S;
    for (int i = 1; i <= m; i++)
        cin >> x >> y >> z, add(x, y, z);
    dij(S);
    for (int i = 1; i <= n; i++)
        cout<<dis[i]<<' ';
}