#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int dp[N];//cnt 0 > cnt1
int dp2[N];//cnt 1> cnt 0;
string a;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>a;
    string str="0";
    str+=a;
    // cout<<str<<endl;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+(str[i]=='1'?-1:1);
        if(i>=3)
        {
            // int k=0;
            // for(int j=i-2;j<=i;j++)
            // {
            //     if(str[j]=='1')k--;
            //     else k++;
            // }
            // cout<<"ik"<<i<<' '<<k<<endl;
            // cout<<k<<endl;
            // cout<<dp[i-3]<<' '<<k<<endl;
            dp[i]=max(dp[i],dp[i-3]);
        }
    }
    // for(int i=1;i<=n;i++)   cout<<dp[i]<<endl;
    dp2[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp2[i]=dp2[i-1]+(str[i]=='1'?1:-1);
        if(i>=3)
        {
            // int k=0;
            // for(int j=i-2;j<=i;j++)
            // {
            //     if(str[i]=='0')k--;
            //     else k++;
            // }
            dp2[i]=max(dp2[i],dp2[i-3]);
        }
    }
    // cout<<dp[n]<<dp2[n]<<endl;
    cout<<max(dp[n],dp2[n])<<endl;
}