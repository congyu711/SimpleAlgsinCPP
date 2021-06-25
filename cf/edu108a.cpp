//
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long  r,b,d;
    cin>>r>>b>>d;
    int minn=min(r,b);
    int maxx=max(r,b);
    if(maxx>minn+minn*d)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
