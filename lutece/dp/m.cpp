#include <bits/stdc++.h>
using namespace std;
const int N = 510;
typedef long long LL;
const LL inf = 1e12+7;
int n,m;
LL dp[N][N];
vector<int> adj[N];
LL v[N];
void dfs(int h,int cap)
{
    dp[h][1]=v[h];
    dp[h][0]=0;
    for(auto e:adj[h])
    {
        dfs(e,max(0,cap-1));
        for(int w=cap;w>=1;w--)
        {
            for(int k=0;k<w;k++)
            {
                dp[h][w]=max(dp[h][w],dp[h][w-k]+dp[e][k]);
                // cout<<dp[1][w]<<endl;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=-inf;
    int fa;
    for(int i=2;i<=n;i++)
    {
        cin>>fa;
        adj[fa].push_back(i);
    }
    for(int i=1;i<=n;i++)   cin>>v[i];
    v[1]+=inf;
    dfs(1,m);
    LL ans=-inf;
    for(int i=1;i<=m;i++)   ans=max(ans,dp[1][i]);
    cout<<ans-inf<<endl;
}