#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,m,a,b;
vector<int> adj[N];
int col[N];

void dfs(int u)
{
    if(vis[u])
    {
        
    }
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

}