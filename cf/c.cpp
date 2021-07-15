#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
int n;
int a[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    
    LL ans=0;
    ans+=n;ans+=(n-1);
    if(n>=3) 
    for(int i=1;i<n-1;i++)
    {
        if((a[i+2]>=a[i+1]&&a[i+1]>=a[i])||(a[i+2]<=a[i+1]&&a[i+1]<=a[i])) ;
        else ans++;
    }
    if(n>=4)
    {
        for(int i=1;i<n-2;i++)
        for(int j=0;j<=3;j++)
        {
            vector<int> f;
            for(int k=0;k<4;k++)
            {
                if(k==j)    continue;
                f.push_back(a[i+k]);
            }
            for(auto e:f)   cout<<e<<endl;
            if((f[0+2]>=f[0+1]&&f[0+1]>=f[0])||(f[0+2]<=f[0+1]&&f[0+1]<=f[0])) ;
            else ans++;
        }
    }
    cout<<ans<<endl;
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
