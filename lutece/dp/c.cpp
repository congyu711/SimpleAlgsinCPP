#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const LL mod = 1e9+7;
int n,nn;
int arr[N];
LL dp[N];
LL subs[N];
inline int lowbit(int x){return x&-x;}
void add(int x,LL v)
{
    while(x<=nn)
    {
        dp[x]+=v;
        dp[x]%=mod;
        x+=lowbit(x);
    }
}
LL getsum(int x)
{
    LL res=0;
    while(x>=1)
    {
        res+=dp[x];
        res%=mod;
        x-=lowbit(x);
    }
    return res%mod;
}
int main()
{
    LL ans=0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i],nn=max(nn,arr[i]);
    for(int i=1;i<=n;i++)
    {
        LL tmp=getsum(arr[i]);
        // cout<<"getsum"<<tmp<<endl;
        tmp*=(1LL*arr[i]);
        tmp+=arr[i];
        tmp-=subs[arr[i]];
        tmp%=mod;
        // cout<<tmp<<' '<<subs[arr[i]]<<endl;
        ans+=tmp;
        ans%=mod;

        add(arr[i],tmp);
        subs[arr[i]]+=tmp;
        subs[arr[i]]%=mod;
    }
    cout<<ans%mod<<endl;
}