#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int fa[N],sz[N];
int a,b;
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
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++)
        fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        if(_find(a)==_find(b))  ans++;
        else merge(a,b);
    }
    cout<<ans<<endl;
}