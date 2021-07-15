#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
void solve()
{
    int a,b,n;
    string s;
    cin>>n>>a>>b;
    cin>>s;
    vector<int> f;
    for(int i=0;i<s.length();)
    {
        int cnt=0;
        char c=s[i];
        while(i<s.length()&&s[i]==c)
        {
            cnt++;
            i++;
        }
        f.push_back(cnt);
    }
    // for(auto e:f)   cout<<e<<endl;
    if(b>0)
    {
        cout<<a*n+b*n<<endl;
    }
    else
    {
        int ans=0;
        ans+=(a*n);
        ans+=((f.size()+2)/2)*b;
        cout<<ans<<endl;
    }
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