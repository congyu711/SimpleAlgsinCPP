#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int N = 3e5+10;
const int sz=N<<5;
int ifo[sz],ls[sz],rs[sz],rt[sz];
int arr[N],id[N];
int tot,m,n;
int build(int l,int r)
{
	int rt=++tot;
	if(l==r)	return rt;
	int mid=l+r>>1;
	ls[rt]=build(l,mid);
	rs[rt]=build(mid+1,r);
	return rt;
}
int add(int pre,int l,int r,int v)
{
	int rt=++tot;
	ls[rt]=ls[pre],rs[rt]=rs[pre],ifo[rt]=ifo[pre]+1;
	if(l==r)	return rt;
	int mid=l+r>>1;
	if(v>mid)//rson
		rs[rt]=add(rs[pre],mid+1,r,v);
	else ls[rt]=add(ls[pre],l,mid,v);
	return rt;
}
int query(int x,int y,int l,int r,int k)
{
	if(l==r)	return ifo[y]-ifo[x];
	int lnum=ifo[ls[y]]-ifo[ls[x]];
    int rnum=ifo[rs[y]]-ifo[rs[x]];
	int mid=l+r>>1;
    if(lnum>k)  return query(ls[x],ls[y],l,mid,k);
    if(rnum>k)  return query(rs[x],rs[y],mid+1,r,k);
    return 0;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		arr[i]=read();
		// id[i]=arr[i];
	}
	// sort(id+1,id+n+1);
	// int len=unique(id+1,id+n+1)-id-1;
	// for(int i=1;i<=n;i++)
	// 	arr[i]=lower_bound(id+1,id+len+1,arr[i])-id;
	rt[0]=build(1,n);
	for(int i=1;i<=n;i++)
		rt[i]=add(rt[i-1],1,n,arr[i]);

	for(int i=1;i<=m;i++)
	{
		int ll,rr,kk;
		ll=read();rr=read();kk=(rr-ll+2)>>1;
		int ans=query(rt[ll-1],rt[rr],1,n,kk);
        printf("%d\n",max(1,2*ans-(rr-ll+1)));
	}
}