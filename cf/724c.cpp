#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;

void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int cntd=0,cntk=0;
    map<pair<int,int>,int> mp;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='D')  cntd++;
        else cntk++;
        int gcd=__gcd(cntd,cntk);
        pair<int,int> tmp=make_pair(cntd/gcd,cntk/gcd);
        cout<<mp[tmp]+1<<' ';
        mp[tmp]++;
    }
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