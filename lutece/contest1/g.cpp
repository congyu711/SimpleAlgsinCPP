#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL cnt0[N],cnt1[N];
void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            cnt1[i+1]=cnt1[i]+1;
            cnt0[i+1]=cnt0[i];
        }
        else
        {
            cnt0[i+1]=cnt0[i]+1;
            cnt1[i+1]=cnt1[i];
        }
    }
    LL ans=inf;
    int n=s.length();
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,min(cnt1[i]+cnt0[n]-cnt0[i],cnt0[i]+cnt1[n]-cnt1[i]));
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