//倍增LCA
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n,m,a,b;
vector<int> adj[N];
int fa[N][35],sz[N],dep[N];

void dfs(int u,int f)
{
    fa[u][0]=f;
    dep[u]=dep[f]+1;
    for(int i=1;i<=30;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    sz[u]=1;
    for(auto e:adj[u])
    {
        if(e==f)    continue;
        dfs(e,u);
        sz[u]+=sz[e];
    }
    // cout<<u<<' '<<sz[u]<<endl;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])   swap(x,y);
    while(dep[x]>dep[y])
    {
        int d=dep[x]-dep[y];
        // cout<<d<<' '<<(int)log2(d)<<endl;
        x=fa[x][(int)log2(d)];
    }
    if(x==y)    return y;
    for(int k=(int)log2(dep[x]);k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
            x=fa[x][k],y=fa[y][k];
    }
    return fa[x][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef CONGYU
    //

    #endif
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dep[1]=1;
    dfs(1,0);
    // cout<<lca(4,5)<<endl;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        int l=lca(a,b);
        if(a==b)
        {
            cout<<n<<endl;
            continue;
        }
        if(dep[a]==dep[b])
        {
            for(int k=(int)log2(dep[a]);k>=0;k--)
            {
                if(fa[a][k]!=fa[b][k])
                    a=fa[a][k],b=fa[b][k];
            }
            cout<<n-sz[a]-sz[b]<<endl;
        }
        else
        {
            if(dep[a]<dep[b])   swap(a,b);
            int len=dep[a]+dep[b]-2*dep[l];
            if(len%2==1)  cout<<0<<endl;
            else{
                int aa=a,bb=b,length=len/2;
                // cout<<length<<endl;
                for(int k=(int)log2(dep[a]);k>=0;k--)
                {
                    if(dep[a]-dep[fa[aa][k]]<length)
                        aa=fa[aa][k];
                }
                cout<<sz[fa[aa][0]]-sz[aa]<<endl;
            }
        }
    }
}