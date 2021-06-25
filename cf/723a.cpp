//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[55];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n*2;i++)   cin>>arr[i];
    sort(arr+1,arr+1+2*n);
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<' '<<arr[n*2-i+1]<<' ';
    }
    cout<<endl;

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
