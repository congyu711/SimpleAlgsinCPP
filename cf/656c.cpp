//https://codeforces.com/problemset/problem/1385/C
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(auto &e:arr)
        cin>>e;
    int i;
    for( i=arr.size()-1;i>=0;i--)
    {
        if(arr[i-1]<arr[i]) break;
    }
    for(;i>=0;i--)
    {
        if(arr[i-1]>arr[i]) break;
    }
    cout<<max(0,i)<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}
