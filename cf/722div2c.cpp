//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

int n;
ll ans;
vector<int> adj[N];
ll dp[N][2],a[N][2];
void dfs(int i,int fa)
{
    for(auto u:adj[i])
    {
        if(u==fa)   continue;
        dfs(u,i);
        dp[i][0]+=max(dp[u][0]+abs(a[i][0]-a[u][0]),dp[u][1]+abs(a[i][0]-a[u][1]));
        dp[i][1]+=max(dp[u][0]+abs(a[i][1]-a[u][0]),dp[u][1]+abs(a[i][1]-a[u][1]));
    }
}
void solve()
{
    cin>>n;
    for(auto &e:adj)    e.clear();
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
        cin>>a[i][0]>>a[i][1];
    int x,y;
    for(int i=2;i<=n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}
