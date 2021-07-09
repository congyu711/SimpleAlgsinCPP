#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL a[N];
int n;
void solve()
{
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   sum+=a[i];
    //sum%=n;
    LL c=sum%n;
    //cout<<c<<endl;
    cout<<c*(n-c)<<endl;
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