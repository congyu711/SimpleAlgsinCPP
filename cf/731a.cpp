#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;

void solve()
{   
    int xa,ya,xb,yb,a,b;
    cin>>xa>>ya>>xb>>yb>>a>>b;
    if(ya==yb&&yb==b&&a<max(xa,xb)&&a>min(xa,xb))  cout<<abs(xa-xb)+abs(ya-yb)+2<<endl;
    else if(xa==xb&&xb==a&&b<max(ya,yb)&&b>min(ya,yb)) cout<<abs(xa-xb)+abs(ya-yb)+2<<endl;
    else    cout<<abs(xa-xb)+abs(ya-yb)<<endl;
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