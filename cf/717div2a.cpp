//
#include<bits/stdc++.h>
using namespace std;

int t;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(auto &e:arr)
    {
        cin>>e;
    }
    int cnt=0;
    while(k--)
    {
        while(cnt<n-1&&arr[cnt]==0) cnt++;
        arr[cnt]--;
        arr[n-1]++;
    }
    for(auto e:arr)
    {
        cout<<e<<' ';
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        solve();
    }
}
