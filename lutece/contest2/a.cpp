#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL INF = 1e18+10;;
const double eps=1e-3;
const double pi=acos(-1);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double a,b;
    double ans=0.0;
    for(a=0;a<pi;a+=eps)
    {
        for(b=0;b<pi;b+=eps)
        {
            ans+=fabs(sin(a*a+b));
        }
    }
    cout<<ans<<endl;
}