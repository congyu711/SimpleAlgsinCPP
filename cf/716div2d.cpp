//https://codeforces.com/contest/1514/problem/D
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> tb[300005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        tb[arr[i]].push_back(i);
    }
    mt19937 rng;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int ans=1;
        for(int i=1;i<=40;i++)
        {
            int c=arr[uniform_int_distribution<int>(l,r)(rng)];
            int f=upper_bound(tb[c].begin(),tb[c].end(),r)-
            lower_bound(tb[c].begin(),tb[c].end(),l);
            ans=max(ans,2*f-(r-l+1));
        }
        cout<<ans<<endl;
    }
}
