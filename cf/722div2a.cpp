//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[200];
void solve()
{
    int n;
    cin>>n;
    int cnt=0;
    int minn=0x7fffffff;
    for(int i=1;i<=n;i++)  { cin>>arr[i];minn=min(minn,arr[i]);}
    for(int i=1;i<=n;i++) 
    {
        if(arr[i]==minn)    cnt++;
    }
    cout<<n-cnt<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)  solve();
}
