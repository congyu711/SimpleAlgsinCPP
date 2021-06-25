#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
LL n,k,x,arr[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+n+1);
    vector<LL> tmp;
    for(int i=1;i<n;i++)
    {
        if(arr[i+1]-arr[i]>x)
        {
            LL aa=ceil(double(arr[i+1]-arr[i])/double(x))-1;
            tmp.push_back(aa);
        }
    }
    sort(tmp.begin(),tmp.end());
    // for(auto e:tmp) cout<<e<<' ';
    // cout<<endl;
    LL ans=tmp.size()+1;
    for(auto e:tmp)
    {
        if(k>=e)
        {
            ans--;
            k-=e;
        }
        else break;
    }
    cout<<ans<<endl;
}