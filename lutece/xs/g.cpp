#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 998244353;
LL base=26+26+10;
LL quickpow(LL a,LL b)
{
    LL ans=1;
    while(b>0)
    {
        if(b&1) ans = a*ans%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    LL n;
    string a;
    LL ans=0;
    cin>>n;
    cin>>a;
    int len=a.length();
    ans=quickpow(base,n);
    ans-=(quickpow(base,n-len)*(n-len+1)%mod);
    while(ans<0)    ans+=mod;
    ans%=mod;
    cout<<ans<<endl;
}