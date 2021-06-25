//
#include <bits/stdc++.h>
using namespace std;

int t;
void solve()
{
    int n;
    cin >> n;
    int xxx = 0;
    int a;
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        ans[i]=ans[i-1]^a;
    }
    if(ans[n]==0)
    {
        cout<<"YES"<<endl;
        return ;
    }
    bool res=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            res|=((ans[i]^ans[j])==ans[i])&&(ans[i]==(ans[n]^ans[j]));
        }
    }
    if(res==0)
    {
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
        solve();
}
