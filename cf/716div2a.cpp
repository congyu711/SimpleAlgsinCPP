//
#include<bits/stdc++.h>
using namespace std;
int t;

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(auto e:arr)
    {
        if(e!=(int)sqrt(e)*(int)sqrt(e))
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return ;  
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
        solve();
}
