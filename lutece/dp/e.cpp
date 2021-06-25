#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
LL fib[100];
LL dp[100][2];
LL cnt;
inline LL getans(LL x)
{
    return (x+1)>>1;
}
void solve()
{
    memset(dp,0,sizeof(dp));
    LL n;
    cin>>n;
    stack<LL> st;
    vector<LL> vec;
    vec.push_back(0);
    LL c=n;
    for(int i=cnt;i>=1;i--)
    {
        if(c==fib[i])
        {
            cout<<(i+1>>1)<<endl;
            return;
        }
        if(n>=fib[i])
        {
            st.push(i);
            n-=fib[i];
        }
    }
    while(!st.empty())
    {
        LL tmp=st.top();
        st.pop();
        vec.push_back(tmp);
    }
    // for(auto e:vec)
    //     cout<<e<<endl;
    dp[1][0]=1;
    dp[1][1]=getans(vec[1])-1;
    int nn=vec.size()-1;
    for(int i=2;i<=nn;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];

        dp[i][1]=1LL*dp[i-1][0]*((vec[i]-vec[i-1]-1)/2)+
                 1LL*dp[i-1][1]*((vec[i]-vec[i-1])/2);
        // cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
    }
    cout<<(LL)(dp[nn][0]+dp[nn][1])<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fib[1]=1,fib[2]=2;
    for(cnt=3;;cnt++)
    {
        fib[cnt]=fib[cnt-1]+fib[cnt-2];
        if(fib[cnt]>1e18)   break;
    }
    int t;
    cin>>t;
    while(t--)
        solve();
}
/*
2
20
21
*/