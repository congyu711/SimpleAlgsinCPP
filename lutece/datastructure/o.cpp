#include<bits/stdc++.h>
using namespace std;
int i;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int N = 3e5+10;
const int sz=N<<5;
int ls[sz],rs[sz],rt[sz],fa[sz];
int lls[sz],rrs[sz],rrt[sz],siz[sz];
// pair<int,int> dst[sz];//first->father,second->sz
int arr[N],id[N];
int tot,m,n,siztot;
int build(int l,int r)//建树的时候完全一样
{
	int rt=++tot;
    siztot=tot;
	if(l==r)	{fa[rt]=l,siz[rt]=1;return rt;}
	int mid=l+r>>1;
	lls[rt]=ls[rt]=build(l,mid);
	rrs[rt]=rs[rt]=build(mid+1,r);
	return rt;
}
int addfather(int pre,int l,int r,int idx,int father)
{
	int rt=++tot;
	ls[rt]=ls[pre],rs[rt]=rs[pre];
	if(l==r){fa[rt]=father;return rt;}
	int mid=l+r>>1;
	if(idx>mid)//rson 
		rs[rt]=addfather(rs[pre],mid+1,r,idx,father);
	else ls[rt]=addfather(ls[pre],l,mid,idx,father);
	return rt;
}
int addsize(int pre,int l,int r,int idx,int SZ)
{
	int rt=++siztot;
	lls[rt]=lls[pre],rrs[rt]=rrs[pre];
	if(l==r){siz[rt]=SZ;return rt;}
	int mid=l+r>>1;
	if(idx>mid)//rson
		rrs[rt]=addsize(rrs[pre],mid+1,r,idx,SZ);
	else lls[rt]=addsize(lls[pre],l,mid,idx,SZ);
	return rt;
}
//return idx->fa
int query(int idx,int rt,int l,int r)
{
    int mid=l+r>>1;
    if(l==r)    return fa[rt];
    if(idx>mid) return query(idx,rs[rt],mid+1,r);
    else    return query(idx,ls[rt],l,mid);
}
int querysiz(int idx,int rt,int l,int r)
{
    int mid=l+r>>1;
    if(l==r)    return siz[rt];
    if(idx>mid) return querysiz(idx,rrs[rt],mid+1,r);
    else    return querysiz(idx,lls[rt],l,mid);
}
int _find(int x,int rt)
{
    while(query(x,rt,1,n)!=x)   x=query(x,rt,1,n);
    return  x;
}
void merge(int x,int y,int root)
{
    int fax=_find(x,root),fay=_find(y,root);
    if(fax==fay)    return;
    // int szx=dst[query(fax,root,1,n)].second,szy=dst[query(fay,root,1,n)].second;
    int szx=querysiz(fax,rrt[i],1,n),szy=querysiz(fay,rrt[i],1,n);
    if(szx<szy)
        rt[i]=addfather(rt[i],1,n,fax,fay),rrt[i]=addsize(rrt[i],1,n,fay,szx+szy);
    else
        rt[i]=addfather(rt[i],1,n,fay,fax),rrt[i]=addsize(rrt[i],1,n,fax,szx+szy);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	n=read();m=read();
	rrt[0]=rt[0]=build(1,n);
	for(i=1;i<=m;i++)
    {
        rt[i]=rt[i-1];
        rrt[i]=rrt[i-1];
        int opt;
        opt=read();
        if(opt==1)  
        {
            int a,b;
            a=read();b=read();
            merge(a,b,rt[i]);
        }
        else if(opt==2)
        {
            int x;
            x=read();
            rt[i]=rt[x];
            rrt[i]=rrt[x];
        }
        else{
            int a,b;
            a=read();b=read();
            if(_find(a,rt[i])==_find(b,rt[i]))  printf("1\n");
            else printf("0\n");
        }
    }
}