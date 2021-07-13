#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;

void solve()
{
    string s;
    cin>>s;
    vector<int> arr;
    int i=0;char c=s[0];
    for(;i<s.length();)
    {
        int cnt=0;
        while(i<s.length()&&s[i]==c)
        {
            cnt++;
            i++;
        }
        arr.push_back(cnt);
        if(i==s.length())   break;
        c=s[i];
    }
    // for(auto e:arr) cout<<e<<' ';
    // cout<<endl;
    int ans=mod;
    int n=arr.size();
    int sum=0;
    for(int i=0;i+2<=n;i+=2)
    {
        sum+=arr[i];
    }
    // cout<<"1"<<sum<<endl;
    ans=min(ans,sum);
    sum=0;
    for(int i=1;i+2<=n;i+=2)
    {
        sum+=arr[i];
    }
    // cout<<"2"<<sum<<endl;
    ans=min(ans,sum);
    if(n>=4)
    {
    sum=0;
    for(int i=2;i<n;i+=2)
    {
        sum+=arr[i];
    }
    // cout<<"3"<<sum<<endl;
    ans=min(ans,sum);

    sum=0;
    for(int i=3;i<n;i+=2)
    {
        sum+=arr[i];
    }
    // cout<<"4"<<sum<<endl;
    ans=min(ans,sum);
    }
    if(n==4)
    {
        ans=min(arr[0]+arr[3],ans);
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}