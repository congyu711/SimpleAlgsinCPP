#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    vector<int> presum(n+1);
    for(int i=1;i<=n;i++)
        presum[i]=(presum[i-1]+arr[i])%360;
    sort(presum.begin(),presum.end());
    // sort(presum,presum+n+1+1);
    presum.push_back(360);
    int ans=0;
    for(int i=1;i<=(int)presum.size();i++)
    {
        ans=max(ans,presum[i]-presum[i-1]);
    }
    cout<<ans<<endl;
}