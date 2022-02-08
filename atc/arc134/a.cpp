#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double ld;
LL n,l,w;
LL a[100010];
LL ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>l>>w;
    for(int i=1;i<=n;i++)   cin>>a[i];
    vector<LL> len;len.push_back(a[1]);
    for(int i=2;i<=n;i++)   len.push_back(a[i]-a[i-1]-w);
    len.push_back(l-a[n]-w);
    for(auto e:len)
    {
        // cout<<e<<endl;
        if(e<=0)    continue;
        ans+=ceil(((ld)e/(ld)w));
    }
    cout<<ans<<endl;
}