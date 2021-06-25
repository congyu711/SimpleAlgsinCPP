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
void dfs(int u,int fa)
{
    low[u]=pre[u]=++dfn;
    st.push(u);
    inst[u]=1;

    for(auto v:adj[u])
    {
        if(!pre[v])
        {
            dfs(v,u);
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
        //sccsz[sccno]++;
    }
}
int main()
{
    
}