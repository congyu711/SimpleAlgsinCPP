//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n;
ll dp[N];
ll arr[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    int i=1;
    int ans=1;
    while(i<=n&&arr[i]<0)i++;
    dp[1]=arr[i];
    i++;
    for(;i<=n;i++)
    {
        // if(arr[i]<arr[0])  continue;
        // if(arr[i]>=dp[len])
        // {
        //     len++;
        //     dp[len]=arr[i];
        // }
        // else
        // {
        //     int c=upper_bound(dp+1,dp+1+len,arr[i])-dp;
        //     dp[c]=arr[i];
        // }
        if(arr[i]>=0)
        {
            ans++;
            dp[ans]=dp[ans-1]+arr[i];
        }
        else
        {
            int c=upper_bound(dp+1,dp+1+ans,-arr[i])-dp-1;
            dp[c]+=arr[i];
        }
        cout<<i<<' '<<ans-1<<endl;
        for(int i=1;i<=ans;i++) cout<<dp[i]<<' ';
        cout<<endl<<endl;;
    }
    cout<<ans-1<<endl;
}
