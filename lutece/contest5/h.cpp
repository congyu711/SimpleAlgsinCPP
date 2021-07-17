#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const LL mod = 1e9 + 7;
vector<pair<LL,LL> > adj[N];
bool conn[N][N];
LL n,m,s,t;
LL a,b;
bool vis[N],vis2[N];
LL diss[N],dist[N];
void dijs(LL s)
{
    priority_queue<pair<LL,LL> >pq;
    memset(vis,0,sizeof(vis));
    memset(diss,63,sizeof(diss));
    diss[s]=0;
    pq.push(make_pair(-diss[s],s));
    while (pq.size())
    {
        LL u=pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(LL i=0;i<adj[u].size();i++)
            if(diss[adj[u][i].first]>diss[u]+adj[u][i].second)
            {
                diss[adj[u][i].first] = diss[u]+adj[u][i].second;
                pq.push(make_pair(-diss[adj[u][i].first],adj[u][i].first));
            }
    }    
}
void dijt(LL s)
{
    priority_queue<pair<LL,LL> >pq;
    memset(vis2,0,sizeof(vis2));
    memset(dist,63,sizeof(dist));
    dist[s]=0;
    pq.push(make_pair(-dist[s],s));
    while (pq.size())
    {
        LL u=pq.top().second;
        pq.pop();
        if(vis2[u])
            continue;
        vis2[u]=1;
        for(LL i=0;i<adj[u].size();i++)
            if(dist[adj[u][i].first]>dist[u]+adj[u][i].second)
            {
                dist[adj[u][i].first] = dist[u]+adj[u][i].second;
                pq.push(make_pair(-dist[adj[u][i].first],adj[u][i].first));
            }
    }    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>s>>t;
    for(LL i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(make_pair(b,1));
        adj[b].push_back(make_pair(a,1));
        conn[a][b]=conn[b][a]=1;
    }
    dijs(s);dijt(t);
    LL dis=dist[s];
    LL ans=0;
    // for(int i=1;i<=n;i++)   cout<<diss[i]<<' ';cout<<endl;
    // for(int i=1;i<=n;i++)   cout<<dist[i]<<' ';cout<<endl;
    // cout<<dis<<endl;
    for(LL i=1;i<=n;i++)
    {
        for(LL j=i+1;j<=n;j++)
        {
            if(conn[i][j]||conn[j][i])  continue;
            if(i==j)    continue;
            // cout<<i<<j<<' '<<min((diss[i]+dist[j]+1),(diss[j]+dist[i]+1))<<endl;
            if(((diss[i]+dist[j]+1)>=dis)&&((diss[j]+dist[i]+1)>=dis)) {ans++;}
        }
    }
    cout<<ans<<endl;
}