#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
vector<pair<int,int> > wep[20];//1.money 2.dps
int dp[N];
int n,m;
void solve()
{
    for(auto &e:wep)    e.clear();
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    int u,w;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=4;k++)
        {
            cin>>u>>w;
            wep[i].push_back(make_pair(u,w));
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(auto e:wep[i])
            {
                if(j-e.first>=0)
                    dp[j]=max(dp[j],dp[j-e.first]+e.second);
                ans=max(ans,dp[j]);
            }
        }
    }
    cout<<ans<<endl;
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
/*
3
2 2000
10 5 50 100 100 1000 250 1100
100 1 200 2 300 3 1900 1000
3 100
10 100 40 200 70 300 100 500
5 1 25 2 35 3 50 4
200 10000 300 20000 400 30000 500 40000
1 10
100 2 200 3 300 5 400 6

*/