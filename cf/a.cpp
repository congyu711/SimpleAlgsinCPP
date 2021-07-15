#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
vector<int> a;
void solve()
{   
    LL s;
    cin>>s;
    int i=0;
    for(i=0;i<a.size();i++)
    {
        if(a[i]>=s)  break;
    }
    cout<<i+1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i=1;i*i<=6000;i++)
    {
        a.push_back(i*i);
    }
    // for(auto e:a)   cout<<e<<' ';
    // cout<<endl;
    while (t--)
        solve();
}