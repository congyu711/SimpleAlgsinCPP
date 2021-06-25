//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    priority_queue<pair<int,int>> pq;
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> arr(n,0);
    for(auto &e:arr)
        cin>>e;
    for(int i=1;i<=m;i++)
    {
        pq.push(make_pair(0,i));
    }
    vector<int> ans(n,0);
    for(int i=0;i<arr.size();i++)
    {
        ans[i]=pq.top().second;
        int tmp=pq.top().first-arr[i];
        pq.pop();
        pq.push(make_pair(tmp,ans[i]));
    }
    cout<<"YES"<<endl;
    for(auto e:ans) cout<<e<<' ';
    cout<<endl;
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
