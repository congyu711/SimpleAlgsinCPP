#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
vector<int> adj[N];
int n,m,a,b;
int fa[N],sz[N];
bool vis[N],vis2[N];
int dis[N],dis2[N];
int _find(int p)
{
    if(p!=fa[p])
        fa[p]=_find(fa[p]);
    return fa[p];
}
void merge(int x,int y)
{
    int i=_find(x),j=_find(y);
    if(i==j)    return;
    if(sz[i]<sz[j])
    {
        fa[i]=j;
        sz[j]+=sz[i];
    }
    else
    {
        fa[j]=i;
        sz[i]+=sz[j];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(nullptr));
    cin>>n>>m;
    for(int i=1;i<=n;i++)   fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        merge(a,b);
    }
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        if(sz[i]==n)
        {
            flag=1;break;
        }
    }
    if(flag==0) {cout<<-1<<endl;return 0;}

    LL ans=0;
    int sp=rand()%n+1;
    // cout<<"sp"<<sp<<endl;
    queue<int> q;
    q.push(sp);
    vis[sp]=1;
    dis[sp]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto e:adj[t])
        {
            if(!vis[e]) q.push(e);
            dis[e]=dis[t]+1;
            vis[e]=1;
        }
    }
    int maxx=0,idx=0;
    for(int i=1;i<=n;i++)
        {if(maxx<dis[i]) idx=i,maxx=dis[i];}
    // idx=rand()%n+1;
    // q.push(idx);
    // dis2[idx]=0;
    // vis2[idx]=1;
    // while(!q.empty())
    // {
    //     int t=q.front();
    //     q.pop();
    //     for(auto e:adj[t])
    //     {
    //         if(!vis2[e]) q.push(e);
    //         dis2[e]=dis2[t]+1;
    //         vis2[e]=1;
    //     }
    // }
    // int maxx2=0;
    // for(int i=1;i<=n;i++)
    //    { maxx2=max(maxx2,dis2[i]);}

    // for(int i=1;i<=n;i++)   cout<<dis[i]<<' ';cout<<endl;
    // for(int i=1;i<=n;i++)   cout<<dis2[i]<<' ';cout<<endl;

    cout<<ceil(log2(double(maxx)))+1<<endl;
}