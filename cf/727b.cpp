#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL n,q,l,r;
LL tree[N];
int lowbit(int x){return x&-x;}
void add(int x,int k)
{
    while(x<=n)
    {
        tree[x]=tree[x]+k;
        x+=lowbit(x);
    }
}
LL getsum(LL x)
{
    LL ans=0;
    while(x>=1)
    {
        ans=ans+tree[x];
        x-=lowbit(x);
    }
    return ans;
}
string s;
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        char a;
        cin>>a;
        add(i,(a-'a'+1));
    }
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        cout<<getsum(r)-getsum(l-1)<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
}