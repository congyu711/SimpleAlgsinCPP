#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
const int mod=1e9+7;
int p[N];
int n;
LL dp[N][2];//1 分子 0 分母
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
LL getinv(LL x)
{
    return quickpow(x,mod-2)%mod; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>p[i];
    dp[0][0]=1;dp[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=1LL*(dp[i-1][1]+dp[i-1][0])*100;//fenzi
        dp[i][1]%=mod;
        dp[i][0]=1LL*dp[i-1][0]*p[i];//fenmu
        dp[i][0]%=mod;
    }
    LL inv=getinv(dp[n][0]);
    cout<<(1LL*dp[n][1]*inv)%mod<<endl;
}