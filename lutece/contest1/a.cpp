#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL a[N],b[N];
LL n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++)   cin>>b[i];
    LL gcd=a[1];
    for(int i=2;i<=n;i++)   gcd=__gcd(gcd,a[i]);
    
    
}