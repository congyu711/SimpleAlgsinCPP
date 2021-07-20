#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int cnt1[222],cnt2[222];


void solve()
{
    int n;
    int t;
    cin>>n;
    int a0=1,a1=1;
    vector<int> f1,f2;
    
    for(int i=0;i<n;i++)
    {
        cout<<"? "<<0<<' '<<i<<endl;
        cout<<flush;
        cin>>t;
        f1.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        cout<<"? "<<1<<' '<<i<<endl;
        cout<<flush;
        cin>>t;
        f2.push_back(t);
    }
    for(auto e:f1)
    {
        cnt1[e]++;
    }
    for(auto e:f2)
    {
        cnt2[e]++;
    }
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt1[i]>maxx)
        {
            maxx=cnt1[i];
            a0=i;
        }
    }
    maxx=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt2[i]>maxx)
        {
            maxx=cnt2[i];
            a1=i;
        }
    }
    // cout<<a0<<' '<<a1<<endl;
    if(a0>a1)
    {
        for(int i=0;i<n;i++)
        {
            if(f1[i]==a0&&f2[i]==a0)
            {
                cout<<"! "<<(i+n)%n<<endl;
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(f2[i]==a1&&f1[i]==a1)
            {
                cout<<"! "<<(i-1+n)%n<<endl;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int T;
    // cin>>T;
    // while(T--)
        solve();
}