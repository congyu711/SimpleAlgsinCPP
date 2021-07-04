#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6+10;

void solve()
{
    int a,b;
    cin>>a>>b;
    if((double)b/(double)a>6.0||(double)b/(double)a<1.0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin>>t;
    // while(t--)
        solve();
}