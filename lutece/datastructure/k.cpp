#include<bits/stdc++.h>
using namespace std;
//root=1

//  y1  0   1 
//  y2  2   3 
//      x1  x2
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

#define son0(x) (x<<2)-2
#define son1(x) (x<<2)-1
#define son2(x) x<<2
#define son3(x) (x<<2)|1
const int N = 2e6+10;
class node
{
public:
    int tag=0;
    int x1,x2,y1,y2;
    long long sum;
};
node st[N<<2];
int a[1010][1010];
int getsz(int h){return (st[h].x2-st[h].x1+1)*(st[h].y2-st[h].y1+1);}
void update(int x)
{
    st[x].sum=st[son0(x)].sum+st[son1(x)].sum+st[son2(x)].sum+st[son3(x)].sum;
}
void pushdown(int h)
{
    if(st[h].tag==0)    return;
    //if st[h] cunzai
    if(st[son0(h)].x1)    st[son0(h)].sum+=getsz(son0(h))*st[h].tag,st[son0(h)].tag+=st[h].tag;
    if(st[son1(h)].x1)    st[son1(h)].sum+=getsz(son1(h))*st[h].tag,st[son1(h)].tag+=st[h].tag;
    if(st[son2(h)].x1)    st[son2(h)].sum+=getsz(son2(h))*st[h].tag,st[son2(h)].tag+=st[h].tag;
    if(st[son3(h)].x1)    st[son3(h)].sum+=getsz(son3(h))*st[h].tag,st[son3(h)].tag+=st[h].tag;
    st[h].tag=0;
}
void build(int root,int x1,int x2,int y1,int y2)
{
    st[root].x1=x1,st[root].x2=x2,st[root].y1=y1,st[root].y2=y2;
    if(x1==x2&&y1==y2)
    {
        st[root].sum=a[x1][y1];
        return;
    }
    int midx= x1+x2>>1;
    int midy= y1+y2>>1;
    if(x1==x2){build(son0(root),x1,x2,y1,midy);build(son2(root),x1,x2,midy+1,y2);}
    else if(y1==y2){build(son0(root),x1,midx,y1,y2);build(son1(root),midx+1,x2,y1,y2);}
    else {
        build(son0(root),x1,midx,y1,midy);
        build(son1(root),midx+1,x2,y1,midy);
        build(son2(root),x1,midx,midy+1,y2);
        build(son3(root),midx+1,x2,midy+1,y2);
    }
    update(root);
}
void add(int h,int x1,int x2,int y1,int y2,int value)
{
    if(st[h].x1>x2||st[h].x2<x1||st[h].y1>y2||st[h].y2<y1)  return;
    if(st[h].x1>=x1&&st[h].x2<=x2&&st[h].y1>=y1&&st[h].y2<=y2)
    {
        st[h].sum+=getsz(h)*value;
        st[h].tag+=value;
        return;
    }
    pushdown(h);
    add(son0(h),x1,x2,y1,y2,value);
    add(son1(h),x1,x2,y1,y2,value);
    add(son2(h),x1,x2,y1,y2,value);
    add(son3(h),x1,x2,y1,y2,value);
    update(h);
}
long long query(int h,int x1,int x2,int y1,int y2)
{
    long long ans=0ll;
    if(st[h].x1>x2||st[h].x2<x1||st[h].y1>y2||st[h].y2<y1)  return 0;
    if(st[h].x1>=x1&&st[h].x2<=x2&&st[h].y1>=y1&&st[h].y2<=y2)  return st[h].sum;
    pushdown(h);

    ans+=query(son0(h),x1,x2,y1,y2);
    ans+=query(son1(h),x1,x2,y1,y2);
    ans+=query(son2(h),x1,x2,y1,y2);
    ans+=query(son3(h),x1,x2,y1,y2);
    //update(h);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream infile;
    infile.open("testcase1.in");
    int n,m,q;
    infile>>n>>m>>q;
    // n=read();m=read();q=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            infile>>a[i][j];
            // a[i][j]=read();
    build(1,1,n,1,m);
    for(int i=1;i<=q;i++)
    {
        int opt,a,b,c,d;
        infile>>opt>>a>>b>>c>>d;
        // opt=read();a=read();b=read();c=read();d=read();
        if(opt==1)
        {
            int v;
            infile>>v;
            // v=read();
            add(1,a,c,b,d,v);
        }
        if(opt==2)
        {
            cout<<query(1,a,c,b,d)<<endl;
        }
    }
}