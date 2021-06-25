#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 110;
const LL inf = INTMAX_MAX;
const LL mod = 1e9+7;
LL a[N];
LL sum[N];
LL dp[110][5010];
int n,m;
bool cmp(const LL &a,const LL &b){return a>b;}

int main()
{
    memset(dp,0x7f,sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)   sum[i]=sum[i-1]+a[i];
    dp[1][1]=0;dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=m;j++)
        {
            for(int k=0;k<=i;k++)
            {
                if(k==0&&i!=j)
                {
                    dp[i][j]=dp[i][j-i];
                    // cout<<i<<j<<' '<<dp[i][j]<<endl;
                }
                else
                {
                    dp[i][j]=min(dp[i][j],dp[i-k][j-k]+(sum[i]-sum[i-k])*(i-k));
                    // cout<<i<<j<<' '<<dp[i][j]<<endl;
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
}