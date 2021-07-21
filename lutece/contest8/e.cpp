#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
class node
{
public:
    LL r,l;
};
bool cmp(const node &a,const node &b)
{
    if(a.l==b.l)
    {
        return a.r<b.r;
    }
    return a.l<b.l;
}
node lr[N];
LL n,s;
void solve()
{
    cin>>n>>s;
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>lr[i].l>>lr[i].r;
        sum+=lr[i].l;
    }
    sort(lr+1,lr+n+1,cmp);
    LL mid=lr[n/2+1].l;
    
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