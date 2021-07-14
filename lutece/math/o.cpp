#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
const LL mod=1e9+7;
// #ifdef CONGYU
//     ifstream fin("testcase.in");
// #endif


void solve()
{
    LL n,k;
    cin>>n>>k;
    n%=(2*k);
    if(n>=k)
    {
        cout<<"Kate"<<endl;
    }
    else
    {
        cout<<"Draw"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
}