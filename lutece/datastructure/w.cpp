#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
inline int lson(int x){return x<<1;}
inline int rson(int x){return x<<1|1;}
int n,m;
int arr[N];
vector<int> vec[N];
int dep[N],son[N],fa[N],siz[N],top[N],dfn[N],rnk[N],btm[N];
//segment tree
const int sz=N<<2;
int sum[sz],maxx[sz];
void build(int rt,int l,int r)
{
	if(l==r) {maxx[rt]=sum[rt]=arr[rnk[l]];return;}
	int mid=l+r>>1;
	build(lson(rt),l,mid);
	build(rson(rt),mid+1,r);
    maxx[rt]=max(maxx[lson(rt)],maxx[rson(rt)]);
    sum[rt]=sum[lson(rt)]+sum[rson(rt)];
}
void modify(int idx,int l,int r,int rt,int v)
{
	if(l==r)
    {
        sum[rt]=v;
        maxx[rt]=v;
        return;
    }
    int mid=l+r>>1;
    if(idx<=mid)
        modify(idx,l,mid,lson(rt),v);
    else
        modify(idx,mid+1,r,rson(rt),v);
    sum[rt]=sum[lson(rt)]+sum[rson(rt)];
    maxx[rt]=max(maxx[lson(rt)],maxx[rson(rt)]);
}
int getmax(int ql,int qr,int rt,int l,int r)
{
    if(ql<=l&&r<=qr)
        return maxx[rt];
    int mid=l+r>>1;
    if(ql<=mid)
    {
        if(mid<qr)
            return max(getmax(ql,qr,lson(rt),l,mid),getmax(ql,qr,rson(rt),mid+1,r));
        else return getmax(ql,qr,lson(rt),l,mid);
    }
    else
        return getmax(ql,qr,rson(rt),mid+1,r);
}
int getsum(int ql,int qr,int rt,int l,int r)
{
    if(ql<=l&&r<=qr)
        return sum[rt];
    int mid=l+r>>1;
    if(ql<=mid)
    {
        if(mid<qr)
            return getsum(ql,qr,lson(rt),l,mid)+getsum(ql,qr,rson(rt),mid+1,r);
        else return getsum(ql,qr,lson(rt),l,mid);
    }
    else
        return getsum(ql,qr,rson(rt),mid+1,r);
}
//end st
void dfs1(int h)
{
    siz[h]=1;
    son[h]=-1;//以防他没儿子
    for(int i=0;i<vec[h].size();i++)
    {
        int x=vec[h][i];
        if(dep[x]==0)//没有走过
        {
            dep[x]=dep[h]+1;
            fa[x]=h;
            dfs1(x);
            siz[h]+=siz[x];
            if(son[h]==-1||siz[x]>siz[son[h]])  son[h]=x;
        }
    }
}
int cnt=0;
void dfs2(int h,int t)
{
    cnt++;
    top[h]=t;
    rnk[cnt]=h;
    dfn[h]=cnt;
    if(son[h]==-1)  return;
    dfs2(son[h],t);//dfs先走重链才能保证重链的dfn连续
    for(int i=0;i<vec[h].size();i++)
    {
        int x=vec[h][i];
        if(x!=fa[h]&&x!=son[h]) dfs2(x,x);//没走重儿子说明有一个重链要从x开始
    }
}
int treepathsum(int u,int v)
{
    int res=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]])//v.top>>u.top
            swap(u,v);
        res+=getsum(dfn[top[u]],dfn[u],1,1,n);
        u=fa[top[u]];
    }
    if(dfn[u]>dfn[v])swap(u,v);
    res+=getsum(dfn[u],dfn[v],1,1,n);
    return res;
}

int treepathmax(int u,int v)
{
    int res=INT_MIN;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]])//v.top>>u.top
            swap(u,v);
        res=max(res,getmax(dfn[top[u]],dfn[u],1,1,n));
        u=fa[top[u]];
    }
    if(dfn[u]>dfn[v])swap(u,v);
    res=max(getmax(dfn[u],dfn[v],1,1,n),res);
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;

    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    dep[1]=1;
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    
    int q;
    cin>>q;
    int opt,u;
    for(int i=1;i<=q;i++)
    {
        cin>>opt;
        if(opt==1)
        {
            cin>>u>>a;
            modify(dfn[u],1,n,1,a);
        }
        else if(opt==2)
        {
            cin>>a>>b;
            cout<<treepathsum(a,b)<<endl;
        }
        else
        {
            cin>>a>>b;
            cout<<treepathmax(a,b)<<endl;
        }
    }
}