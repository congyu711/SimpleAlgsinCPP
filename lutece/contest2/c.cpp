#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n<4) {cout<<0<<endl;return 0;}
    LL ans=0;
    for(int i=2;i<=n/2+2;i++)
    {
        LL k=n/i;
        // cout<<k<<endl;
        if(k<=1)    continue;
        ans+=((k+2)*(k-1)/2);
    }
    cout<<ans*4<<endl;
}