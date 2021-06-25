#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
void solve()
{
    int a[5];
    for(int i=1;i<=4;i++)   cin>>a[i];
    int a1=max(a[1],a[2]),a2=max(a[3],a[4]);
    sort(a+1,a+5);
    if((a[4]==a1&&a[3]==a2)||(a[4]==a2&&a[3]==a1))  {cout<<"YES"<<endl;return;}
    cout<<"NO"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)  solve();
}