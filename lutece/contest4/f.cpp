#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;

void solve()
{
    LL a,b;
    cin>>a>>b;
    LL c=2*a-b;
    LL d=2*b-a;
    if(c%3==0&&d%3==0&&c>0&&d>0)    cout<<"YES"<<endl;
    else if(a==0&&b==0) cout<<"YES"<<endl;
    else if(a*2LL==b||b*2LL==a) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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