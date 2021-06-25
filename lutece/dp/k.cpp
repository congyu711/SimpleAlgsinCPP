#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int arr[N];
int dp[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>arr[i];
    int len=1;
    dp[1]=arr[0];
    for(int i=1;i<=n;i++)
    {
        if(arr[i]<arr[0])  continue;
        if(arr[i]>=dp[len])
        {
            len++;
            dp[len]=arr[i];
        }
        else
        {
            int c=upper_bound(dp+1,dp+1+len,arr[i])-dp;
            dp[c]=arr[i];
        }
    }
    cout<<len-1<<endl;
}