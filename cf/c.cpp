#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9+7;
long double cc,mm,pp,v;
double eps=1e-6;
long double dfs(long double c,long double m,long double p,int t)
{
    cout<<t<<endl;
    if(t>10)    return p*10;
    long double ex=0.0;
    ex+=p*(t+1);
    //if(c<=v/2&&m<=v/2)    cout<<t+1<<endl;

    if(c>eps)
    {
        if(c-v>eps)
            ex+=c*dfs(c-v,m+v/2.0,1-m-c+v/2.0,t+1);
        else ex+=c*dfs(0.0,m+c/2.0,1-m-c/2.0,t+1);
    }

    if(m>eps)
    {
        if(m-v>eps)
            ex+=m*dfs(c+v/2.0,m-v,1-m-c+v/2.0,t+1);
        else ex+=m*dfs(c+m/2.0,0.0,1-c-m/2.0,t+1);
    }
    
    //cout<<ex<<endl;
    return ex;
}
void solve()
{
    cin>>cc>>mm>>pp>>v;
    cout<<dfs(cc,mm,pp,0)<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    int T;
    cin>>T;
    while(T--)
        solve();
}
/*
1
0.2 0.2 0.6 0.2
*/