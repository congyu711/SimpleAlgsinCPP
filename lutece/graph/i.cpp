#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
vector<pair<LL,LL> > g1[N],g2[N];//g1 s-> t, g2 t-> s
LL disg1[N],disg2[N];
LL use[N],rt[N],ans[N];
LL n,m,a,b,k,aa,bb;
//segment tree
LL z[N<<2];
inline LL lson(LL x){return x<<1;}
inline LL rson(LL x){return x<<1|1;}
void build(LL rt,LL l,LL r)
{
	if(l==r) {z[rt]=ans[l];return;}
	LL mid=l+r>>1;
	build(lson(rt),l,mid);
	build(rson(rt),mid+1,r);
    z[rt]=min(z[lson(rt)],z[rson(rt)]);
}
void modify(LL idx,LL l,LL r,LL rt,LL v)
{
	if(l==r)
    {
        z[rt]=v;
        return;
    }
    LL mid=l+r>>1;
    if(idx<=mid)
        modify(idx,l,mid,lson(rt),v);
    else
        modify(idx,mid+1,r,rson(rt),v);
    z[rt]=min(z[lson(rt)],z[rson(rt)]);
}
//end seg tree
void dijg1(LL s)
{
    priority_queue<pair<LL,LL> >pq;
    memset(use,0,sizeof(use));
    memset(disg1,63,sizeof(disg1));
    disg1[s]=0;
    pq.push(make_pair(-disg1[s],s));
    while (pq.size())
    {
        LL u=pq.top().second;
        pq.pop();
        if(use[u])
            continue;
        use[u]=1;
        for(LL i=0;i<g1[u].size();i++)
            if(disg1[g1[u][i].first]>disg1[u]+g1[u][i].second)
            {
                disg1[g1[u][i].first] = disg1[u]+g1[u][i].second;
                pq.push(make_pair(-disg1[g1[u][i].first],g1[u][i].first));
            }
    }    
}
void dijg2(LL s)
{
    priority_queue<pair<LL,LL> >pq;
    memset(use,0,sizeof(use));
    memset(disg2,63,sizeof(disg2));
    disg2[s]=0;
    pq.push(make_pair(-disg2[s],s));
    while (pq.size())
    {
        LL u=pq.top().second;
        pq.pop();
        if(use[u])
            continue;
        use[u]=1;
        for(LL i=0;i<g2[u].size();i++)
            if(disg2[g2[u][i].first]>disg2[u]+g2[u][i].second)
            {
                disg2[g2[u][i].first] = disg2[u]+g2[u][i].second;
                pq.push(make_pair(-disg2[g2[u][i].first],g2[u][i].first));
            }
    }    
}
int main()
{
    #ifndef CONGYU
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    #endif
    cin>>n>>m>>k;
    for(LL i=1;i<=m;i++)
    {
        cin>>a>>b>>aa>>bb;
        g1[a].push_back(make_pair(b,aa));
        g2[b].push_back(make_pair(a,bb));
    }
    for(LL i=1;i<=n;i++)
            cin>>rt[i];
    dijg1(1);
    dijg2(n);
    for(LL i=1;i<=n;i++)
        ans[i]=disg1[i]+ceil(double(disg2[i])/double(rt[i]));
    build(1,1,n);
    for(LL i=1;i<=k;i++)
    {
        cin>>a>>b;
        rt[a]=b;
        modify(a,1,n,1,disg1[a]+ceil(double(disg2[a])/double(rt[a])));
        cout<<z[1]<<endl;
    }
}