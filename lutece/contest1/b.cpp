#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
const LL mod=1e9+7;
const LL inf = INTMAX_MAX;
LL a[N];
LL n;
LL quickpow(LL a,LL b)
{
    LL ans=1;
    while(b>0)
    {
        if(b&1) ans = a*ans%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    LL ans=1;
    LL m=0;
    LL cnt=0;
    for(int i=1;i<=n;i++)
    {
        LL t;
        cin>>t;
        if(a[t]==0)cnt++;
        a[t]++;
        m=max(t,m);
    }
    for(int i=2;i<=m;i++)
    {
        if(a[i]!=0)
        {
            LL p=(LL(a[i]*a[i]+a[i])/2LL);
            //cout<<i<<' '<<a[i]<<' '<<p<<endl;
            p=(p*(cnt));
            ans=(ans*(quickpow(i,p)))%mod;
            cout<<i<<' '<<a[i]<<' '<<p<<endl;
        }
    }
    cout<<ans<<endl;
}