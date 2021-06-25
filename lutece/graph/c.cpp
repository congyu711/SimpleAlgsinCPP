
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
const int inf=0x7fffffff;
vector<int> adj[N];
vector<int> mst;
LL n,m,k;
int maxedg=-1;
class edge{
public:
    int u,v,w;
};
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
edge edg[N];
int fa[N];
int findfa(int x)
{
    if(fa[x]==x)    return fa[x];
    else return fa[x]=findfa(fa[x]);
}
void merge(int x,int y)
{
    int fx=findfa(x),fy=findfa(y);
    if(fx!=fy)
    {
        if(rand()%2)
            fa[fy]=fx;
        else fa[fx]=fy;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)   fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>edg[i].u>>edg[i].v>>edg[i].w;
    sort(edg+1,edg+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int u=edg[i].u,v=edg[i].v;
        if(findfa(u)==findfa(v))    continue;
        mst.push_back(i);
        maxedg=max(maxedg,edg[i].w);
        merge(u,v);
    }
    if(k>=maxedg)
    {
        LL ans=inf;
        int c=mst[mst.size()-1];
        for(int i=c;i<=m;i++)
        {
            auto &e=edg[i];
            if(e.u!=e.v)
            {
                ans=min(ans,abs(k-e.w));
            }
        }
        cout<<ans<<endl;
    }
    else
    {
        LL ans=0;
        for(auto i:mst)
        {
            auto e=edg[i];
            if(e.w>k)
            {
                ans+=abs(k-e.w);
            }
        }
        cout<<ans<<endl;
    }
}