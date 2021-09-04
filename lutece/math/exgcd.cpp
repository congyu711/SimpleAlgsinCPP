#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

//ax+by=gcd(a,b) return gcd(a,b)
int __exgcd(LL a,LL b,LL &x,LL &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    LL d=__exgcd(b,a%b,x,y);
    LL tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL x,y;
    cout<<__exgcd(22,16,x,y)<<' '<<x<<' '<<y<<endl;
}