#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;



void solve()
{
    int n,a,x,y;
    cin>>n>>a>>x>>y;
    LL ans=0;
    if(n>=a)
    {
        cout<<a*x+(n-a)*y<<endl;
    }
    else
    {
        cout<<n*x<<endl;
    }
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