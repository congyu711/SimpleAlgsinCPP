#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long LL;
const LL inf = INTMAX_MAX;
vector<int> adj[N];
int sz[N];//子树里有几个标记的点
LL dep[N];
int cnt[N];
int n,m;
LL sum[N];
int ans;
vector<int> res;
void dfs(int h,int fa)
{
    sz[h]=cnt[h];
    if(cnt[h])  sum[1]+=(cnt[h]*dep[h]);
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
        sum[h]=sum[fa]-sz[h]*2+m;
    // cout<<h<<' '<<"sumh"<<sum[h]<<endl;
    if(sum[h]<sum[0])
    {
        // cout<<h<<fa<<"CHAGGE"<<sz[h]<<sz[0]<<endl;
        sum[0]=sum[h];
        res.clear();
        res.push_back(h);
    }
    else if(sum[h]==sum[0])
    {
        res.push_back(h);
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
    cin>>n>>m;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=m;i++)
    {
        int p;
        cin>>p;
        cnt[p]++;
    }
    dep[1]=0;
    
    dfs(1,0);
    sum[0]=sum[1];
    // cout<<"SUM!"<<sum[0]<<endl;
    res.push_back(1);
    dp(1,0);
    ans=0x7fffffff;
    for(auto e:res) ans=min(e,ans);
    cout<<ans<<endl;
    // cout<<endl;
    // for(int i=1;i<=n;i++)   cout<<i<<' '<<sum[i]<<endl;
}