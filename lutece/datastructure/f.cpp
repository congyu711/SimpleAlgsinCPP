#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int N = 1e6+10;
int arr[N];
int n;
stack<pair<long long, long long>> big,big2;
int lpos[N], rpos[N];
stack<pair<long long, long long>> sm,sm2;
int slpos[N], srpos[N];
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
    for(int i=1;i<=n;i++)
        arr[i]=rand();
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i; j <= n; j++)
        {
            int maxx = 0;
            for (long long k = i; k <= j; k++)
                maxx = max(arr[k], maxx);
            ans += maxx;
            ans %= mod;
            int minn = 0x7fffffff;
            for (long long k = i; k <= j; k++)
                minn = min(arr[k], minn);
            ans += minn;
            ans %=mod;
        }
    }
    for (long long i = 1; i <= n; i++)
    {
        if(i==1)   { lpos[1]=0;big.push(make_pair(arr[i],i));continue;}
        while(!big.empty()&&big.top().first<=arr[i]){big.pop();}
        if(!big.empty()) lpos[i]=big.top().second;
        else lpos[i]=0;
        big.push(make_pair(arr[i],i));
    }
    // for (long long i = 1; i <= n; i++)cout<<lpos[i]<<endl;
    for (long long i = n; i >= 1; i--)
    {
        if(i==n)   { rpos[n]=n+1;big2.push(make_pair(arr[i],i));continue;}
        while(!big2.empty()&&big2.top().first<arr[i]){big2.pop();}
        if(!big2.empty()) rpos[i]=big2.top().second;
        else rpos[i]=n+1;
        big2.push(make_pair(arr[i],i));
    }
    // for (long long i = 1; i <= n; i++)cout<<rpos[i]<<endl;
    long long res=0;
    for(long long i=1;i<=n;i++)
    {
        res+=(i-lpos[i])*arr[i]*(rpos[i]-i);
        res%=mod;
    }
    for (long long i = 1; i <= n; i++)
    {
        if(i==1)   { slpos[1]=0;sm.push(make_pair(arr[i],i));continue;}
        while(!sm.empty()&&sm.top().first>=arr[i]){sm.pop();}
        if(!sm.empty()) slpos[i]=sm.top().second;
        else slpos[i]=0;
        sm.push(make_pair(arr[i],i));
    }
    for (long long i = n; i >= 1; i--)
    {
        if(i==n)   { srpos[n]=n+1;sm2.push(make_pair(arr[i],i));continue;}
        while(!sm2.empty()&&sm2.top().first>arr[i]){sm2.pop();}
        if(!sm2.empty()) srpos[i]=sm2.top().second;
        else srpos[i]=n+1;
        sm2.push(make_pair(arr[i],i));
    }
    for(long long i=1;i<=n;i++)
    {
        res+=(i-slpos[i])*arr[i]*(srpos[i]-i);
        res%=mod;
    }
    cout<<"Lpos"<<endl;
    for(int i=1;i<=n;i++)
        cout<<lpos[i]<<' ';
    cout<<endl;
    cout<<"Rpos"<<endl;
    for(int i=1;i<=n;i++)
        cout<<rpos[i]<<' ';
    cout<<endl;
    
    cout<<"res"<<res<<endl;
    cout<<"ans"<<ans<<endl;
    res%=mod;
    long long fenmu=(n*(n+1))%mod;
    fenmu%=mod;
    long long cd=__gcd(fenmu,res);
    fenmu/=cd;
    res/=cd;
    long long inv=getinv(fenmu);
    cout<<(res*inv)%mod<<endl;
}