//增广路求二分图最大匹配
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=310;
int a,r,n;
vector<int> adj[N];
int res,dfscolck;
int lf[N],rt[N],dfn[N];

bool findap(int u)
{
    dfn[u]=dfscolck;
    //直接就一条未匹配边
    for(auto v:adj[u])
    {
        if(rt[v]==-1)
        {
            lf[u]=v;
            rt[v]=u;
            return 1;
        }
    }
    //v全是盖点
    for(auto v:adj[u])
    {
        if(dfn[rt[v]]!=dfn[u])
        {
            bool c=findap(rt[v]);
            if(c)
            {
                lf[u]=v;
                rt[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    for(auto &e:adj) e.clear();
    res=dfscolck=0;
    memset(lf,-1,sizeof(lf));
    memset(rt,-1,sizeof(rt));
    memset(dfn,0,sizeof(dfn));
    cin>>r>>n;
    for(int i=1;i<=r;i++)
    {
        int t;cin>>t;
        if(t==0)
        {cout<<"NO"<<endl;return;}
        for(int j=1;j<=t;j++)
        {
            cin>>a;
            adj[i].push_back(a);
        }
    }
    while(1)
    {
        int cnt=0;
        ++dfscolck;
        for(int i=1;i<=n;i++)
            if(lf[i]==-1)
            {
                bool c=findap(i);
                if(c)   cnt++;
            }
        res+=cnt;
        if(cnt==0)
            break;
    }
    if(res>=r)  cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--)
        solve();
}