#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n;
int a[N],b[N];
LL dp[N][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   cin>>b[i];
    dp[1][0]=a[1];
    dp[1][1]=b[1];
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+b[i]);
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
}