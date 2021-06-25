#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
int arr[200];
int n;
void solve()
{
    memset(arr,0,sizeof(arr));
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        if(arr[i]<0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl<<101<<endl;
    for(int i=0;i<=100;i++) cout<<i<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)  solve();
}