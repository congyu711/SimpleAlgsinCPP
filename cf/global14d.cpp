//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> lsc(n + 1, 0), rsc(n + 1, 0);
    int c;
    ll ans = 0;
    for (int i = 1; i <= l; i++)
    {
        cin >> c;
        lsc[c]++;
    }
    for (int i = 1; i <= r; i++)
    {
        cin >> c;
        rsc[c]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int c = min(lsc[i], rsc[i]);
        lsc[i] -= c, rsc[i] -= c;
        l-=c;
        r-=c;
    }
    if(l<r)
    {
        swap(lsc,rsc);
        swap(l,r);
    }
    for(int i=1;i<=n;i++)
    {
        int mvb=lsc[i]/2;
        int mv=min(mvb*2,l-r);
        l-=mv;
        ans+=mv/2;
    }
    ans+=(l-r)/2;
    ans+=(l+r)/2;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
