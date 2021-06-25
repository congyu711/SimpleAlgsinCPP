#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
LL fib[10000];
LL cnt;
void solve()
{
    LL n;
    cin>>n;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fib[1]=1,fib[2]=2; 
    for(cnt=3;;cnt++)
    {
        fib[cnt]=fib[cnt-1]+fib[cnt-2];
        if(fib[cnt]>1e18)   break;
    }
    int t;
    cin>>t;
    while(t--)
        solve();
}