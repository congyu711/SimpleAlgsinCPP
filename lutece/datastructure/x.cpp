#include<bits/stdc++.h>
using namespace std;
const int N = 3e4+10;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
inline int lson(int x){return x<<1;}
inline int rson(int x){return x<<1|1;}

const int sz=N<<2;
int sum[sz],maxx[sz];
int arr[N];
int m,n;
void build(int rt,int l,int r)
{
	if(l==r) {maxx[rt]=sum[rt]=arr[l];cout<<rt<<l<<"leaf"<<endl;return;}
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
        sum[l]+=v;
        maxx[l]=max(maxx[l],maxx[l]+v);
    }
    int mid=l+r>>1;
    if(idx<=mid)
        modify(idx,l,mid,lson(rt),v);
    else modify(idx,mid+1,r,rson(rt),v);
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
int main()
{
	n=read();m=read();

    for(int i=1;i<=n;i++)
    {
        arr[i]=read();
    }
    build(1,1,n);
    

}