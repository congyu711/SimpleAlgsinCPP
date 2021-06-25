#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int a[2010];
int n;

void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int cnt=n*(n-1)/2;
    int cnt2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(__gcd(a[i],a[j])==1&&a[i]%2&&a[j]%2) cnt2++;
        }
    }
    cout<<cnt-cnt2<<endl;
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