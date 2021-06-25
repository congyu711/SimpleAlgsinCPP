//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> arr(n, 0ll);
    ll ans=0;
    for (auto &e : arr)
    {
        cin >> e;
        ans+=e;
    }
    if(ans==x)
    {
        cout<<"NO"<<endl;
        return;
    }
    ans=0;
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        ans+=arr[i];
        if(ans==x)
        {
            ans-=arr[i];
            if(i!=n-1)
                swap(arr[i],arr[i+1]);
            else swap(arr[i],arr[i-1]);
            ans+=arr[i];
            cout<<arr[i]<<' ';
        }
        else{
            cout<<arr[i]<<' ';
        }
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
