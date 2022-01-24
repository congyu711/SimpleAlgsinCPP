#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
class edge
{
public:
    int a,b,c,q;
    bool operator<(const edge & e)
    {
        return c<e.c;
    }
};
edge edges[N];
int n,m,q;
int a,b,c;
int fa[N];
int findfa(int x)
{
    if(fa[x]!=x)    return fa[x]=findfa(fa[x]);
    return x;
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
    cin.tie(nullptr);
    cin>>n>>m>>q;
    vector<bool> ans(q+1);
    for(int i=1;i<=n;i++)   fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        auto & e=edges[i];
        cin>>e.a>>e.b>>e.c;
    }
    for(int i=1;i<=q;i++)
    {
        auto &e=edges[i+m];
        e.q=i;
        cin>>e.a>>e.b>>e.c;
    }
    sort(edges+1,edges+m+q+1);
    for(int i=1;i<=m+q+1;i++)
    {
        auto e=edges[i];
        int fax=findfa(e.a),fay=findfa(e.b);
        if(fax==fay)    continue;
        if(e.q!=0)
        {
            ans[e.q]=1;
            continue;
        }
        merge(fax,fay);
    }
    for(int i=1;i<=q;i++)
        if(ans[i])  cout<<"Yes\n";
        else cout<<"No\n";
}