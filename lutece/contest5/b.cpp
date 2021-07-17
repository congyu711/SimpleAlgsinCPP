#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n;
int a[N];
double l[N],r[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(a[1]<a[n])
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}