#include <bits/stdc++.h>
using namespace std;
int mm, nn;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int a[300010];
vector<int> vec[300010];
// struct node
// {
//     int l, r;
//     int spfele;
//     void init(int p)
//     {
//         l = r = p;
//         spfele=a[p];
//     }
// };
int cnt(int l,int r,int x)
{   
    return upper_bound(vec[x].begin(),vec[x].end(),r)-
    lower_bound(vec[x].begin(),vec[x].end(),l);
}
// node operator+(const node &l, const node &r)
// {
//     node ans;
//     ans.l = l.l;
//     ans.r = r.r;
//     int fre1=cnt(ans.l,ans.r,l.spfele);
//     int fre2=cnt(ans.l,ans.r,r.spfele);
//     ans.spfele=fre1>fre2?l.spfele:r.spfele;
//     return ans;
// }

// node z[1200010];

// void update(int rt)
// {
//     z[rt] = z[rt << 1] + z[rt << 1 | 1];
// }

// void build(int l, int r, int rt)
// {
//     if (l == r)
//     {
//         z[rt].init(l);
//         return;
//     }
//     int m = (l + r) >> 1;
//     build(lson);
//     build(rson);
//     update(rt);
// }

// int query(int l, int r, int rt, int st, int ed)
// {
//     if (st <= l && r <= ed)
//         return cnt(st,ed,z[rt].spfele);
//     int m = (l + r) >> 1;
//     if (st <= m)
//     {
//         if (m < ed)
//             return max(query(lson, st, ed) , query(rson, st, ed));
//         else
//             return query(lson, st, ed);
//     }
//     else
//         return query(rson, st, ed);
// }

int main()
{
    nn=read();
    mm=read();
    for (int i = 1; i <= nn; i++)
    {
        a[i]=read();
        vec[a[i]].push_back(i);
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //build(1, nn, 1);
    for (int i = 1; i <= mm; i++)
    {
        int l, r;
        l=read();
        r=read();
        int ans=1;
        for(int ii=1;ii<=9;ii++)
        {
            int c=a[uniform_int_distribution<int>(l,r)(rng)];
            ans=max(ans,2*cnt(l,r,c)-(r-l+1));
        }
        //cout<<max(1,query(1,nn,1,l,r) * 2-(r-l+1))<<endl;
        cout<<ans<<endl;
    }
}
/*
5 2
1 1 1 4 5
1 5
1 4

*/