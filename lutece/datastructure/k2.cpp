#include <bits/stdc++.h>
using namespace std;
#define LL long long
inline int lowbit(int x){return x & -x;}
const int N = 1e3 + 10;
//tree 存差分
LL tree[N][N][4]; //  0a    1 ia    2ja    3 ija
int n,m; 

//1,1 - x,y +k
void add(int x, int y, LL k)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        for(int j=y;j<=m;j+=lowbit(j))
        {
            tree[i][j][0]+=k;
            tree[i][j][1]+=k*x;
            tree[i][j][2]+=k*y;
            tree[i][j][3]+=k*x*y;
        }
    }
}
//1,1 - x,y sum
LL getsum(int x,int y)
{
    LL a=0,ia=0,ja=0,ija=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        for(int j=y;j>0;j-=lowbit(j))
        {
            a+=tree[i][j][0];
            ia+=tree[i][j][1];
            ja+=tree[i][j][2];
            ija+=tree[i][j][3];
        }
    }
    return (x+1)*(y+1)*a-(y+1)*ia-(x+1)*ja+ija;
}
//x1,y1 - x2,y2 +k
void add(int x1,int y1,int x2,int y2,int k)
{
    add(x2+1,y2+1,k);
    add(x1,y1,k);
    add(x1,y2+1,-k);
    add(x2+1,y1,-k);
}
LL sum(int x1,int y1,int x2,int y2)
{
    return getsum(x2,y2)+getsum(x1-1,y1-1)-getsum(x1-1,y2)-getsum(x2,y1-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    // ifstream infile("testcase1.in");
    cin>>n>>m>>q;
    int c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>c;
            add(i,j,i,j,c);
        }
    for(int i=1;i<=q;i++)
    {
        int opt,a,b,c,d;
        cin>>opt>>a>>b>>c>>d;
        if(opt==1)
        {
            int v;
            cin>>v;
            add(a,b,c,d,v);
        }
        if(opt==2)
        {
            cout<<sum(a,b,c,d)<<endl;
        }
    }
}