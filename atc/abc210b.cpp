#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;



void solve()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            if(i%2==1)
            {
                cout<<"Aoki"<<endl;
                return;
            }
            else
            {
                cout<<"Takahashi"<<endl;
                return;
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