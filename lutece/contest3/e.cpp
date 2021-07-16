#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n;
int f[N],tot;

void solve()
{
    cin>>n;
    if(n<100)
    {
        for(int i=1;i<=n;i++)   cout<<1;
        cout<<337<<endl;
        return;
    }
    int a,b,cha=mod;
    for(int i=10;i<=tot;i++)
    {
        int c=n/f[i];
        if(c==0)    break;
        int eps=n-c*f[i]+i+c;
        if(eps<=cha)
        {
            cha=eps;
            a=i;
        }
    }
    b=n/f[a];
    // cout<<a<<b<<cha<<endl;
    for(int i=1;i<=b;i++)   cout<<1;
    for(int i=1;i<=a-2;i++) cout<<3;
    for(int i=1;i<=n-b*f[a];i++) cout<<1;
    cout<<337<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i*(i-1)/2<1e9;i++)
    {
        f[i]=(i-1)*i/2;
        tot=i;
    }
    // cout<<tot<<endl;
    while(t--)
        solve();
}