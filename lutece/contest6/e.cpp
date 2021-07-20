#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,k,cnt;
int f[200];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=1;(1<<(i-1))<=200;i++)
    {
        f[i]=(1<<(i-1));
        cnt++;
    }
    // for(int i=1;i<=cnt;i++) cout<<f[i]<<' ';cout<<endl;
    int ts=0;
    for(int i=1;i<=200;i++)
    {
        if(((1<<i)-1)>n)
        {
            ts=i-1;
            break;
        }
        if(((1<<i)-1)==n)
        {
            ts=i;
            break;
        }
    }
    // cout<<ts<<endl;
    if(ts<k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=k-1;i++)
        {
            cout<<f[i]<<' ';
        }
        cout<<n-((1<<(k-1))-1)<<endl;
    }
}