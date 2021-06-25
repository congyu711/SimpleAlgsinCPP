#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long LL;
LL n,m,q,p,k;
int x[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)   cin>>x[i];
    for(int i=1;i<=q;i++)
    {
        cin>>p>>k;
        LL len=(LL)x[k]*p;
        len%=(2*m);
        if(len>m)cout<<2*m-len<<endl;
        else cout<<len<<endl;
    }
}