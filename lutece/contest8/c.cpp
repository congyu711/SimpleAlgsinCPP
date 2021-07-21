#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,t;
int a[N];


void solve()
{
    cin>>n;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==1)    cnt1++;
        else cnt2++;
    }
    if(cnt2!=0)
    {
        cout<<2<<' ';
        if((cnt1%2)==1)
        {
            for(int i=1;i<=cnt1;i++)    cout<<1<<' ';
            for(int i=1;i<=cnt2-1;i++)  cout<<2<<' ';
        }
        else
        {
            for(int i=1;i<=cnt1-1;i++)    cout<<1<<' ';
            for(int i=1;i<=cnt2-1;i++)  cout<<2<<' ';
            if(cnt1>1)
                cout<<1<<' ';
        }
    }
    else
    {
        for(int i=1;i<=cnt1;i++)    cout<<1<<' ';
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int T;
    // cin>>T;
    // while(T--)
    solve();
}