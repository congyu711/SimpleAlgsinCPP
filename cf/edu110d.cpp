#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
LL k,q;
int dp[262150];
string s,aa;
void dfs(int h)
{
    if(h>=(1<<k-1))
    {
        if(s[h]=='?')   dp[h]=2;
        else dp[h]=1;
        return;
    }
    dfs(h<<1);dfs(h<<1|1);
    if(s[h]=='?')   dp[h]=dp[h<<1]+dp[h<<1|1];
    else if(s[h]=='1')   dp[h]=dp[h<<1];
    else dp[h]=dp[h<<1|1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    cin>>aa;
    s+='?';
    for(int i=aa.length()-1;i>=0;i--)
    {
        s+=aa[i];
    } 
    // cout<<s;
    cin>>q;
    int a;char b;
    dfs(1);
    for(int i=1;i<=q;i++)
    {
        cin>>a>>b;
        // cout<<a<<b<<endl;
        int p=s.length()-a;
        s[p]=b;
        while(p>=1)
        {
            if(p>=(1<<k-1))
            {
                if(s[p]=='?')   dp[p]=2;
                else dp[p]=1;
                if(p%2) p=(p-1)>>1;
                else p>>=1;
                continue;
            }
            if(s[p]=='?')   dp[p]=dp[p<<1]+dp[p<<1|1];
            else if(s[p]=='1')   dp[p]=dp[p<<1];
            else dp[p]=dp[p<<1|1];
            if(p%2) p=(p-1)>>1;
            else p>>=1;
        }
        // cout<<s<<endl;
        // for(int i=1;i<=(1<<k)-1;i++)   cout<<dp[i];
        // cout<<endl;
        cout<<dp[1]<<endl;
    }
}