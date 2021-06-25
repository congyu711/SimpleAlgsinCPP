#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long LL;
int dp[N];
int n;
int arr[N];
void solve()
{
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    int comgcd=arr[1];
    for(int i=2;i<=n;i++)
    {
        comgcd=__gcd(comgcd,arr[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==comgcd)  cnt++;
    }
    if(cnt==0)
    {
        cout<<1<<endl;
        return;
    }
    else 
    {
        cout<<(cnt+1)/2<<endl;
        return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)  solve();
}