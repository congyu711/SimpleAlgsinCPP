#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;

char g[66][66];
int n,m;

void solve()
{
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='A')    cnt++;
        }
    }
    if(cnt==n*m)
    {
        cout<<0<<endl;
        return;
    }
    if(cnt==0)
    {
        cout<<"MORTAL"<<endl;
        return;
    }
    bool l=0,r=0,u=0,d=0,lr=0,ud=0;
    for(int i=1;i<=n;i++)
    {
        if(g[i][1]=='A')    l=1;
        if(g[i][m]=='A')    r=1;
        if(lr)  continue;
        lr=1;
        for(int j=1;j<=m;j++)
        {
            if(g[i][j]!='A')    lr=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(g[1][i]=='A')    u=1;
        if(g[n][i]=='A')    d=1;
        if(ud)  continue;
        ud=1;
        for(int j=1;j<=n;j++)
        {
            if(g[j][i]!='A')    ud=0;
        }
    }
    bool f=1;
    for(int i=1;i<=n;i++)   if(g[i][1]!='A')    f=0;
    if(f==1)   {cout<<1<<endl;return;}
    f=1;
    for(int i=1;i<=n;i++)   if(g[i][m]!='A')    f=0;
    if(f==1)   {cout<<1<<endl;return;}
    f=1;
    for(int i=1;i<=m;i++)   if(g[1][i]!='A')    f=0;
    if(f==1)   {cout<<1<<endl;return;}
    f=1;
    for(int i=1;i<=m;i++)   if(g[n][i]!='A')    f=0;
    if(f==1)   {cout<<1<<endl;return;}
    if(lr||ud)
    {
        cout<<2<<endl;
        return;
    }
    if(g[1][1]=='A'||g[1][m]=='A'||g[n][1]=='A'||g[n][m]=='A')
    {
        cout<<2<<endl;
        return;
    }
    if(l||r||u||d)
    {
        cout<<3<<endl;
        return;
    }
    cout<<4<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}