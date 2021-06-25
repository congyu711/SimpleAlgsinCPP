//https://codeforces.com/contest/1509/problem/C
#include<bits/stdc++.h>
using namespace std;
long long arr[2010];
long long n;
long long dp[2001][2001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(long long i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(long long i=1;i<=n;i++)   dp[i][i]=0;
    for(long long l=n;l>=1;l--)
    {
        for(long long r=l;r<=n;r++)
        {
            dp[l][r]=min(dp[l+1][r],dp[l][r-1])+arr[r]-arr[l];
        }
    }

    cout<<dp[1][n]<<endl;
}
