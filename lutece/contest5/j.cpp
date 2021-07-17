#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,a,b;


void solve()
{
    string s;
    cin>>n>>a>>b;
    cin>>s;
    vector<int> f,g;
    int i=0;
    while(i<n&&s[i]=='0') i++;
    for(;i<n;)
    {
        int cnt=0,cnt2=0;
        while(i<n&&s[i]=='1') i++,cnt2++;
        while(i<n&&s[i]=='0')  i++,cnt++;
        f.push_back(cnt);
        g.push_back(cnt2);
    }
    LL ans=(1LL*n*a)+(1LL*(n+1)*b);
    LL t=0;
    
    if(g.size())
    for(auto e:g)   ans+=(1LL*(e+1LL)*b);
    if(f.size())
    for(int i=0;i<f.size()-1;i++)
    {
        ans+=min((1LL*(f[i]-1)*b),2LL*a);
        // cout<<ans<<endl;
    }
    if(g.size())
        ans+=(2LL*a);
    cout<<ans<<endl;
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