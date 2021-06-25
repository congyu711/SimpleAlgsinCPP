//
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> s(n),u(n);
    for(auto &e:u)  {cin>>e;e--;}
    for(auto &e:s)  cin>>e;
    vector<vector<int>> cal(n);
    for(int i=0;i<n;i++)  
    {
        cal[u[i]].push_back(s[i]);
    }
    for(int i=0;i<n;i++)
    {
        sort(cal[i].begin(),cal[i].end(),greater<int>());
    }
    vector<vector<long long>> pre(n,vector<long long>(1,0));
    for(int i=0;i<n;i++)
        for(auto e:cal[i])  pre[i].push_back(pre[i].back()+e);
    vector<long long > ans(n);
    for(int i=0;i<n;i++)
    {
        for(int k=1;k<=cal[i].size();k++)
        {
            ans[k-1]+=pre[i][cal[i].size()/k*k];
        }
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
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