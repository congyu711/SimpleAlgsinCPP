#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
int n,k;
LL tmp[N],a[N],t;
LL dpl[N],dpr[N];
void solve()
{
    cin>>n>>k;
    for(int i=0;i<=n+1;i++)
    {
        a[i]=0;
        dpl[i]=dpr[i]=0x7fffffff;
    }
    for(int i=1;i<=k;i++)   cin>>tmp[i];
    for(int i=1;i<=k;i++)
    {
        cin>>t;
        a[tmp[i]]=t;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0)
            dpl[i]=min(dpl[i-1]+1,a[i]);
        else dpl[i]=dpl[i-1]+1;
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]!=0)
            dpr[i]=min(dpr[i+1]+1,a[i]);
        else dpr[i]=dpr[i+1]+1;
    }
    for(int i=1;i<=n;i++)   cout<<min(dpl[i],dpr[i])<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}

/*
1
4
1 2 4 8
*/