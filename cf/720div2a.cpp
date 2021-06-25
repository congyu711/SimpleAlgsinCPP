//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll a,b;
    cin>>a>>b;
    if(b==1)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<a*(b-1)<<' '<<a*(b+1)<<' '<<a*b*2<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
