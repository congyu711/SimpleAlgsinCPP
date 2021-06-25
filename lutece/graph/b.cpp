//dinic
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+10;
const int INF=0x7ffffff;
int n,m,S,T;
inline int getn(int x,int y){return (x-1)*m+y;}
class edge{
public:
    LL frm,to,cap,flw;
    edge(int _frm,int _to,int _cap,int _flw):
    frm(_frm),to(_to),cap(_cap),flw(_flw){}
};
vector<edge> edg;
vector<int> g[N];
int dep[N],cur[N];
void add(int f,int t,int cap)
{
    edg.push_back(edge(f,t,cap,0));
    edg.push_back(edge(t,f,cap,0));
    int sz=edg.size();
    g[f].push_back(sz-2);
    g[t].push_back(sz-1);
}
bool bfs()
{
    memset(dep,0,sizeof(dep));
    queue<int> q;
    q.push(S);
    dep[S]=1;
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        for(int i=0;i<g[tmp].size();i++)
        {
            auto &e=edg[g[tmp][i]];
            if(dep[e.to]==0&&e.flw<e.cap)
            {
                dep[e.to]=dep[tmp]+1;
                q.push(e.to);
            }
        }
    }
    return dep[T];
}
LL dfs(int u,LL _flw)
{
    LL flow=0;
    if(u==T)    return _flw;
    if(_flw==0) return 0;
    for(int &i=cur[u];i<g[u].size();i++)
    {
        edge &e=edg[g[u][i]];
        if(dep[u]+1==dep[e.to])
        {
            LL c=dfs(e.to,min(_flw,e.cap-e.flw));
            if(c>0)
            {
                e.flw+=c;
                edg[g[u][i]^1].flw-=c;
                flow+=c;
                _flw-=c;
                if(_flw==0) break;
            }
        }
    }
    return flow;
}
LL solve()
{
    LL res=0;
    while(bfs())
    {
        memset(cur,0,sizeof(cur));
        res+=dfs(S,INF);
        // cout<<res<<endl;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int tmp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++)
        {
            cin>>tmp;
            add(getn(i,j),getn(i,j+1),tmp);
        }
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>tmp;
            add(getn(i,j),getn(i+1,j),tmp);
        }
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
        {
            cin>>tmp;
            add(getn(i,j),getn(i+1,j+1),tmp);
        }
    S=1;T=getn(n,m);
    cout<<solve()<<endl;
}