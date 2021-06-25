#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long LL;
const LL inf = INTMAX_MAX;
vector<int> adj[N];
int sz[N];
LL dep[N];
int n,m;
LL ans,sum[N];
void dfs(int h,int fa)
{
    sz[h]=1;
    sum[1]+=dep[h];
    for(auto e:adj[h])
    {
        if(e==fa)   continue;
        dep[e]=dep[h]+1;
        dfs(e,h);
        sz[h]+=sz[e];
    }
}
void dp(int h,int fa)
{
    if(h!=1)
        sum[h]=sum[fa]+n-2*sz[h];
    if(sum[h]>sum[0])
    {
        ans=h;
        sum[0]=sum[h];
    }
    for(auto e:adj[h])
    {
        if(e==fa)   continue;
        dp(e,h);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1]=0;
    sum[0]=sum[1];
    ans=1;
    dfs(1,0);
    dp(1,0);
    cout<<ans<<endl;
}