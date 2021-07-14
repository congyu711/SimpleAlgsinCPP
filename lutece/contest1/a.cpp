#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL a[N],b[N];
LL n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++)   cin>>b[i];
    LL min=inf,idx=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            idx=i;
        }
    }
    LL gcd=0;
    for(int i=1;i<=n;i++)
    {
        if(i==idx)  continue;
        a[i]-=min;
        gcd=__gcd(gcd,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<__gcd(gcd,min+b[i])<<' ';
    }
    cout<<endl;
}