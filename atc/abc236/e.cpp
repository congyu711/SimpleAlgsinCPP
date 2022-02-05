#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010],c[100010];
double dp[100010][2];
bool checkavg(double avg)
{
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i]-avg;
    }
    if(max(dp[n][0],dp[n][1])>0)    return 1;
    else return 0;
}
bool checkmed(int med)
{
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=max(dp[i-1][0],dp[i-1][1])+((a[i]-med>=0)?1:-1);
    }
    if(max(dp[n][0],dp[n][1])>0)    return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    double l=1,r=1e9+10,mid;
    while(r-l>(1e-5))
    {
        mid=(l+r)/2;
        if(checkavg(mid))   l=mid;
        else r=mid;
    }
    cout<<mid<<endl;
    int ll=1,rr=1e9+10,mm;
    while(ll<rr-1)
    {
        mm=ll+rr>>1;
        // cout<<ll<<' '<<rr<<' '<<mm<<'\n';
        if(checkmed(mm)) ll=mm;
        else rr=mm;
    }
    cout<<ll<<endl;
}