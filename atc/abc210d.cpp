#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX/4LL;
const int mod = 1e9 + 7;
LL c,h,w;
LL dp[N][N],x[N][N],a[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>h>>w>>c;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>a[i][j];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            dp[i][j]=min(a[i][j],min(dp[i-1][j],dp[i][j-1])+c);
        }
    }
    LL ans=inf;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            x[i][j]=min(dp[i-1][j],dp[i][j-1])+c+a[i][j];
            ans=min(ans,x[i][j]);
            // cout<<x[i][j]<<' ';
        }
        // cout<<endl;
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            dp[i][j]=min(a[h-i+1][j],min(dp[i-1][j],dp[i][j-1])+c);
        }
    }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            x[i][j]=min(dp[i-1][j],dp[i][j-1])+c+a[h-i+1][j];
            ans=min(ans,x[i][j]);
            // cout<<x[i][j]<<' ';
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
}