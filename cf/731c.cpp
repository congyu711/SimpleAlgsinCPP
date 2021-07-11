#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;


void solve()
{
    int k,n,m;
    cin>>k>>n>>m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++)   cin>>b[i];
    vector<int> ans;
    for(int i=1,j=1;i<=n||j<=m;)
    {
        if(i<=n&&a[i]==0)
        {
            ans.push_back(0);
            i++;k++;
        }
        else if(j<=m&&b[j]==0)
        {
            ans.push_back(0);
            j++;k++;
        }
        else if(i<=n&&a[i]<=k)
        {
            ans.push_back(a[i]);
            i++;
        }
        else if(j<=m&&b[j]<=k)
        {
            ans.push_back(b[j]);
            j++;
        }
        else
        {
            cout<<-1<<endl;
            return;
        }
    }
    for(auto e:ans) cout<<e<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}
/*
1
0.2 0.2 0.6 0.2
*/