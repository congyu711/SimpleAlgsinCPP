#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
vector<int> adj[N];
int n,m,k;
int a,b,x,y;
bool vis[N];
bool col[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(k==1)
    {
        cout<<n<<endl;
        return 0;
    }
    else if(k>2)
    {
        cout<<1<<endl;
        return 0;
    }
    else
    {
        queue<int> q;
        col[1]=0;
        q.push(1);
        while(q.size())
        {
            int u=q.front();
            q.pop();
            vis[u]=1;
            for(auto v:adj[u])
            {
                if(!vis[v])
                {
                    q.push(v);
                }
                if(vis[v]&&((!col[u])!=col[v]))
                {
                    cout<<1<<endl;
                    return 0;
                }
                col[v]=(!col[u]);
            }
        }
        int cnt0=0,cnt1=0;
        for(int i=1;i<=n;i++)
        {
            if(col[i])  cnt1++;
            else cnt0++;
        }
        cout<<max(cnt0,cnt1)<<endl;
    }
}