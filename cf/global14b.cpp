//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 vector<ll> arr;
bool c2(int n)
{
    if(n%2!=0)  return 0;
    int c=n/2;
    for(auto e:arr)
    {
        if(e==c)
        {
            return 1;
        }
    }
    return 0;
}
bool c4(int n)
{
    if(n%4!=0)  return 0;
    int c=n/4;
    for(auto e:arr)
    {
        if(e==c)
            return 1;
    }
    return 0;
}
void solve()
{
    int n;
    cin>>n;
    if(c2(n)||c4(n))
    {
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1;

    for(ll i=1ll;i*i<1e9+10;i++)
    {
        arr.push_back(i*i);
    }
    // for(auto e:ans)
    //     cout<<e<<endl;
    int t;
    cin >> t;
    while (t--)
        solve();
}
