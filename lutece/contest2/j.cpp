#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL INF = 1e18+10;;

vector<LL> cnt;
void solve()
{
    LL n;
    cin>>n;
    int ans=0;
    for(int i=0;i<cnt.size();i++)
    {
        if(n>=cnt[i])
        {
            n-=cnt[i];
            ans++;
        }
        else break;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //cnt.push_back(0);
    cnt.push_back(1);
    for(LL i=2;i<=30;i++)
    {
        LL ans=LL((1<<i)-1);
        // cout<<ans<<' ';
        ans=(ans+1)*ans/2;
        // cout<<ans<<endl;
        if(ans<0||ans>INF) break;
        cnt.push_back(ans);
    }
    //for(auto e:cnt) cout<<e<<endl;
    int t;
    cin>>t;
    while(t--)  solve();
}