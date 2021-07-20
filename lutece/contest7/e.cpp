#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;



void solve()
{
    LL n;
    cin>>n;
    if(n==1)
    {
        cout<<"FastestFinger"<<endl;
        return;
    }
    else if(n%2==1)
    {
        cout<<"Ashishgup"<<endl;
        return;
    }
    else if(n==2)
    {
        cout<<"Ashishgup"<<endl;
        return;
    }
    else
    {
        int cnt=0;
        while(n%2==0)   n/=2,cnt++;
        if(n==1)
        {
            cout<<"FastestFinger"<<endl;
            return;
        }
        bool p=0;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                p=1;
                break;
            }
        }
        // cout<<p<<endl;
        if(cnt==1)
        {
            if(p==0)
            {
                cout<<"FastestFinger"<<endl;
                return;
            }
            else
            {
                cout<<"Ashishgup"<<endl;
                return;
            }
        }
        else
        {
            cout<<"Ashishgup"<<endl;
            return;
        }
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}