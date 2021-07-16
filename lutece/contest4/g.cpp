#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;

void solve()
{
    LL r,b,k;
    cin>>r>>b>>k;
    if(r<b) swap(r,b);
    LL lcm=r*b/__gcd(r,b);
    LL tr=lcm/r,tb=lcm/b;
    LL tt=ceil(((double)tb-1.0)/(double(tr)));
    if(tt>=k)   cout<<"REBEL"<<endl;
    else cout<<"OBEY"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}