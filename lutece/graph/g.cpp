//拓扑序+dp
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=50010;
vector<int> adj[N];
LL n,m;
int a,b;
vector<int> topord;
bitset<N> dp[N];
bool vis[N];

void dfs(int h)
{
    for(auto e:adj[h])
    {
        if(!vis[e])
            dfs(e);
    }
    vis[h]=1;
    topord.push_back(h);
}
void topsort()
{
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    topsort();
    // for(auto e:topord)  cout<<e<<' ';
    // cout<<endl;
    for(auto h:topord)
    {
        dp[h].set(h,1);
        for(auto e:adj[h])
        {
            dp[h]|=dp[e];
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dp[i].count()<<endl;
}
/*
6 5
1 2
4 2
2 3
3 5
5 6

*/