//https://codeforces.com/problemset/problem/1513/C
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int t, n;
int dp[200010];
void solve()
{
    int m;
    string a;
    cin>>a;
    cin>>m;
    long long int ans = 0;
    for(int i=0;i<a.length();i++)
    {
        ans+=dp[(int)(a[i]-'0')+m];
        //cout<<a<<' '<<ans<<endl;
        ans %= mod;
    }
    cout<<ans<<endl;
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<10;i++)
    {
        dp[i]=1;
    }
    for(int i=10;i<=2e5+10;i++)
    {
        dp[i]=dp[i-9]+dp[i-10];
        dp[i]%=mod;
    }

    cin >> t;
    while (t--)
        solve();
}
