#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL n,t,ans;
LL a[N];


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ans=0;
        cin>>t;
        LL c=0;
        LL p=t;
        while(t)
        {
            c+=(t%10);
            t/=10;
        }
        cout<<(p*c)<<endl;
    }
    // cout<<ans<<endl;
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