#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int n,m,a,b;
int sccno,scc[N],sccsz[N];
vector<int> adj[N];
int pre[N],low[N];
int dfn=0;
bool inst[N];
stack<int> st;
//强连通分量
void dfs(int u)
{
    low[u]=pre[u]=++dfn;
    st.push(u);
    inst[u]=1;

    for(auto v:adj[u])
    {
        if(!pre[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inst[v])
        {
            low[u]=min(low[u],pre[v]);
        }
    }
    if(low[u]==pre[u])
    {
        ++sccno;
        while(st.top()!=u)
        {
            int c=st.top();
            st.pop();
            scc[c]=sccno;
            //sccsz[sccno]++;
            inst[c]=0;
        }
        scc[u]=sccno;
        inst[u]=0;
        st.pop();
        //sccsz[sccno]++;
    }
}
int f[N],c[N],d[N];
bool check(int x)
{   
    for(auto &e:adj)    e.clear();
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    memset(scc,0,sizeof(scc));
    memset(inst,0,sizeof(inst));
    dfn=0;sccno=0;while(!st.empty())  st.pop();
    for(int i=1;i<=x;i++)
    {
        adj[f[c[i]]].push_back(d[i]);
        adj[f[d[i]]].push_back(c[i]);
    }
    for(int i=1;i<=2*n;i++)
        if(!pre[i]) dfs(i);

    

    for(int i=1;i<=n;i++)
    {
        if(scc[i]==scc[f[i]])
            return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        f[a]=b;
        f[b]=a;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>c[i]>>d[i];
    }
    int l=1,r=m+1,mid;
    while(l+1<r)
    {
        mid=l+r>>1;
        if(check(mid))
            l=mid;
        else    r=mid;
    }
    cout<<l<<endl;
}