#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;

void solve()
{   
    LL a,b;
    cin>>a>>b;
    LL ans=abs(a-b);
    if(ans==0)
    {
        cout<<"0 0"<<endl;
        return;
    }
    else
    {
        LL c=max(a,b)%ans,c1=ans-c;
        cout<<ans<<' '<<min(c,c1)<<endl;
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