#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
const int mod=998244353;
int n,k;
int a[N];
LL mul(LL a, LL b, LL m)
{
    LL s = a * b - (LL)((long double)a * b / m + 0.5) * m;
    return s < 0 ? s + m : s;
}
LL fpow(LL x, LL a, LL m)
{
    LL ans = 1;
    while (a)
    {
        if (a & 1)
            ans = mul(ans, x, m);
        x = mul(x, x, m), a >>= 1;
    }
    return ans;
}
LL c(LL a,LL b)
{
    if(b<0||a<b)    return 0;
    LL u=1,d=1;
    for(int i=a;i>=a-b+1;i--)   u=1ll*u*i%mod;
    for(int i=1;i<=b;i++)   d=1ll*d*i%mod;
    return (u*(fpow(d,mod-2,mod)))%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    LL res=0;
    for(int i=2;i<=n;i++)
        res+=a[i];
    if(res>=a[1])
    {
        cout<<0<<endl;
        return 0;
    }
    res=a[1]-res;
    LL ans=c(res-1,k-1);
    for(int i=2;i<=n;i++)
    {
        ans=ans*c(a[i]+k-1,k-1)%mod;
    }
    cout<<ans%mod<<endl;
}