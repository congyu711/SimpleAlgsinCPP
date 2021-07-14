#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n;
int a[N];
int fl[N],fr[N];
vector<int> ffr,ffl;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(fl[a[i]]==0) fl[a[i]]=i,ffl.push_back(i);
    }
    for(int i=n;i>=1;i--)
    {
        if(fr[a[i]]==0) fr[a[i]]=i,ffr.push_back(i);
    }
    sort(ffr.begin(),ffr.end());
    // for(auto e:ffr) cout<<e<<' ';cout<<endl;
    // for(auto e:ffl) cout<<e<<' ';cout<<endl;
    LL ans=0;
    for(auto e:ffl)
    {
        // cout<<(ffr.size()-(upper_bound(ffr.begin(),ffr.end(),e)-ffr.begin()))<<endl;
        ans+=(ffr.size()-(upper_bound(ffr.begin(),ffr.end(),e)-ffr.begin()));
    }
    cout<<ans<<endl;
}