#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL h[N];
LL n,m,a,b;
vector<pair<LL,LL> > adj[N];
LL dis[N];
bool use[N];
priority_queue<pair<LL, LL>> q;
void dij(LL S)
{
    memset(dis, 63, sizeof(dis));
    dis[S] = 0;
    q.push(make_pair(-dis[S], S));
    while (q.size())
    {
        LL u = q.top().second;
        q.pop();
        if (use[u])
            continue;
        use[u] = 1;
        for (LL i = 0; i < (int)adj[u].size(); i++)
            if (dis[adj[u][i].first] > dis[u] + adj[u][i].second)
            {
                dis[adj[u][i].first] = dis[u] + adj[u][i].second;
                q.push(make_pair(-dis[adj[u][i].first], adj[u][i].first));
            }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        LL c=h[a]-h[b];
        adj[a].push_back(make_pair(b,max(-c,0LL)));
        adj[b].push_back(make_pair(a,max(c,0LL)));
    }

    dij(1);
    LL ans=0;
    for(int i=1;i<=n;i++)   ans=max(ans,h[1]-h[i]-dis[i]);
    cout<<ans<<endl;
}