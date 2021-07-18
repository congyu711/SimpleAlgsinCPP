#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,k;
int a[N],idx[N];
int cnt[N];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)   {cin>>a[i];idx[i]=a[i];}
    sort(idx+1,idx+n+1);
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(idx+1,idx+n+1,a[i])-idx;
    }
    // for(int i=1;i<=n;i++)   cout<<a[i]<<' ';cout<<endl;

    int res=0;
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        if(cnt[a[i]]==0)    ans++;
        cnt[a[i]]++;
    }
    res=ans;
    for(int i=k+1;i<=n;i++)
    {
        if(cnt[a[i]]==0)    ans++;
        cnt[a[i]]++;
        cnt[a[i-k]]--;
        if(cnt[a[i-k]]==0)  ans--;
        res=max(ans,res);
    }
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int T;
    // cin>>T;
    // while(T--)
        solve();
}