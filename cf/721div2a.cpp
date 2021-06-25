//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    int cnt=0;
    while(n) {n>>=1;cnt++;}
    cnt--;
    cout<<(1<<cnt)-1<<endl;
    // int c=n;
    // n--;
    // while(n--)
    // {
    //     c&=n;
    //     if(c==0)   { cout<<n+1<<endl;return;}
    // }
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
