#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL arr[N];
LL l,r;
void solve()
{   
    LL n,x,k;
    cin>>n>>x>>k;
    LL res=k/x;
    //cout<<res<<endl;
    if(n<=res+1)
    {
        cout<<n*(n-1)/2LL<<endl;
    }
    else
    {
        cout<<res*(res+1)/2LL+(n-1-res)*res<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}