#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,a[N],b[N];
bool h1[N],h0[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   cin>>b[i];
    if(a[1]!=b[1])
    {
        cout<<"NO"<<endl;
        return;
    }
    bool m1=0,m0=0;
    for(int i=1;i<=n;i++)
    {

        if(m1)  h1[i]=1;
        else h1[i]=0;
        if(m0)  h0[i]=1;
        else h0[i]=0;   
        if(a[i]==1) m1=1;
        if(a[i]==-1) m0=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]>b[i]&&h0[i]==0)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(a[i]<b[i]&&h1[i]==0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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