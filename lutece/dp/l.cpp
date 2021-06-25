#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
typedef long long LL;
const LL inf = INTMAX_MAX;
int a[N],b[N];
int dp[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++)   cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])  dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

/*
7 7
1 1 4 5 1 4 0
1 9 1 9 8 1 0
*/