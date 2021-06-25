#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=2e5+10;
int n,m,t;
int fa[N],sz[N];
pair<int,int> edge[M];
int ffind(int x)
{
    if(x!=fa[x])    return fa[x]=ffind(fa[x]);
    return x;
}
void merge(int x,int y)
{
    int fax=ffind(x),fay=ffind(y);
    if(fax==fay)    return;
    if(sz[fax]>sz[fay])
    {
        fa[fay]=fax;
        sz[fax]+=sz[fay];
    }
    else
    {
        fa[fax]=fay;
        sz[fay]+=sz[fax];
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)   sz[i]=1,fa[i]=i;
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        edge[i]=make_pair(a,b);
    }
    stack<int> ans;
    for(int i=m;i>0;i--)
    {
        merge(edge[i].first,edge[i].second);
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
        solve();
}