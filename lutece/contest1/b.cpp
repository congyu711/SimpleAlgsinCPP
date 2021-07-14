#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
const LL mod=1e9+7;
const LL inf = INTMAX_MAX;
LL n,t,tot;
LL p[N];
LL pre[N],suf[N];
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
    LL m=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        m=max(t,m);
        if(p[t]==0) tot++;
        p[t]++;
    }
    pre[1]=1;
    for(int i=2;i<=m;i++)
    {
        if(p[t]==0)
        {
            pre[i]=pre[i-1];
        }
        else
        {
            pre[i]=(pre[i-1]*(p[i]+1))%(mod-1);
        }
    }
    suf[m+1]=1;
    for(int i=m;i>=2;i--)
    {
        if(p[t]==0)
        {
            suf[i]=suf[i+1];
        }
        else
        {
            suf[i]=(suf[i+1]*(p[i]+1))%(mod-1);
        }
    }
    LL ans=1;
    for(int i=2;i<=m;i++)
    {
        if(p[i]!=0)
        {
            LL ex=(p[i]+1)*p[i]/2;
            ex%=(mod-1);
            ex=ex*pre[i-1];
            ex%=(mod-1);
            ex=ex*suf[i+1];
            ex%=(mod-1);
            //cout<<i<<' '<<ex<<endl;
            ans*=(quickpow(i,ex));
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}