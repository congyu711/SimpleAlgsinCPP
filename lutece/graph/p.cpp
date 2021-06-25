//割点割边点双连通分量个数和最大边数
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000010;
int n,m,a,b;
vector<int> adj[N];
int pntcnt,edgcnt,bcccnt,bccedg;
int pre[N],post[N],dfn,bccnoedgcnt[N],low[N];
bool iscut[N];
stack<pair<int,int> > edg;
void dfs(int u,int fa)
{
    low[u]=pre[u]=++dfn;
    int ch=0;
    for(auto v:adj[u])
    {
        if(!pre[v])
        {
            edg.push(make_pair(u,v));
            // cout<<"bccedg"<<u<<v<<' '<<bccedg<<endl;
            ch++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=pre[u])
            {
                iscut[u]=1;
                bcccnt++;
                while(1)
                {
                    auto tmp=edg.top();edg.pop();
                    bccnoedgcnt[bcccnt]++;
                    if(tmp.first==u&&tmp.second==v) break;
                }
            }
            if(low[v]>pre[u])
            {
                edgcnt++;
            }
        }
        else if(v!=fa&&pre[v]<pre[u])
        {
            edg.push(make_pair(u,v));
            // cout<<"bccedg"<<u<<v<<' '<<bccedg<<endl;
            low[u]=min(low[u],pre[v]);
        }
    }
    if(fa==u&&ch<2)    iscut[u]=0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b),adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)   if(!pre[i]) dfs(i,i);
    for(int i=1;i<=n;i++)   if(iscut[i])    pntcnt++;
    for(int i=1;i<=bcccnt;i++)   bccedg=max(bccedg,bccnoedgcnt[i]);
    cout<<pntcnt<<' '<<edgcnt<<' '<<bcccnt<<' '<<bccedg<<endl;
}