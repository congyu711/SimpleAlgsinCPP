#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e4 + 10;
const LL inf = INTMAX_MAX;
const LL mod = 1e9+7;
class seq
{
public:
    LL l,r,k;
};
class matrix
{
public:
    LL mat[3][3];
};
matrix ans;
matrix mul(matrix a,matrix b)
{
    matrix res;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            res.mat[i][j]=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                res.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                res.mat[i][j]%=mod;
            }
        }
    }
    return res;
}
void qpow(LL b,matrix base)
{
    while(b)
    {
        if(b&1) ans=mul(ans,base);
        base=mul(base,base);
        b>>=1;   
    }
}
class qwq
{
public:
    LL l,r;
    bool k[3];
};
bool equ(const qwq&a,const qwq&b)
{
    if(a.k[0]==b.k[0]&&a.k[1]==b.k[1]&&a.k[2]==b.k[2])  return 1;
    return 0;
}
bool cmp(const seq&a,const seq&b)
{
    if(a.l==b.l)    return a.r<b.r;
    return a.l<b.l;
}
seq seqs[N];
LL a,b,k,n,m;
LL idx[N<<1];
vector<qwq> col;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {   
        cin>>a>>b>>k;
        idx[2*i-1]=a,idx[2*i]=b;
        seqs[i].l=a,seqs[i].r=b,seqs[i].k=k;
    }
    idx[2*m+1]=2,idx[2*m+2]=n-1;
    sort(idx+1,idx+2*m+3);
    LL leng=unique(idx+1,idx+2*m+3)-idx-1;
    // for(int i=1;i<=m;i++)
    //     seqs[i].l=lower_bound(idx+1,idx+leng+1,seqs[i].l)-idx,\
    //     seqs[i].r=lower_bound(idx+1,idx+leng+1,seqs[i].r)-idx;
    for(int i=1;i<leng;i++)
    {
        qwq a;
        for(int i=0;i<3;i++)    a.k[i]=0;
        a.r=a.l=idx[i];
        col.push_back(a);
        if(idx[i+1]==idx[i]+1)continue;
        a.l=idx[i]+1;
        a.r=idx[i+1]-1;
        col.push_back(a);
    }
    qwq a;for(int i=0;i<3;i++)    a.k[i]=0;
    a.l=a.r=idx[leng];
    col.push_back(a);
    
    for(int i=1;i<=m;i++)
    {
        for(auto &e:col)
        {
            if(e.l>seqs[i].r)   break;
            if(e.l>=seqs[i].l&&e.r<=seqs[i].r)  e.k[seqs[i].k]=1;
        }
    }
    // for(auto e:col)
    // {
    //     cout<<e.l<<' '<<e.r<<' '<<e.k[0]<<e.k[1]<<e.k[2]<<endl;
    // }


    for(int i=0;i<3;i++)
        ans.mat[i][i]=1;
    matrix b;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            b.mat[i][j]=1;
        b.mat[0][2]=0,b.mat[2][0]=0;
    

    for(auto e:col)
    {
        matrix base=b;
        for(int kk=0;kk<3;kk++)
        {
            if(e.k[kk])
            {
                for(int i=0;i<3;i++)
                    base.mat[kk][i]=0;
            }
        }  
            qpow(e.r-e.l+1,base);
    }

    cout<<(ans.mat[1][1]+ans.mat[2][1]+ans.mat[0][1])%mod<<endl;
}
/*
6 3
2 3 0
4 5 1
3 3 2

*/