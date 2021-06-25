#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
int n;
int arr[N];
bool cmp(int a,int b)
{
    return a>b;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    if(n==2)
    {
        cout<<arr[1]<<' '<<arr[2]<<endl;
        return;
    }
    
    int minn=mod;
    int pos;
    for(int i=1;i<n;i++)
    {
        if(arr[i+1]-arr[i]<=minn)
        {
            minn=arr[i+1]-arr[i];
            pos=i;
        }
    }
    cout<<arr[pos]<<' ';
    for(int i=pos+2;i<=n;i++)
    {
        cout<<arr[i]<<' ';
    }
    for(int i=1;i<pos;i++)
        cout<<arr[i]<<' ';
    cout<<arr[pos+1]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}