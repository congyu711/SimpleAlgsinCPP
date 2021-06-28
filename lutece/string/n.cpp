#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e6 + 10;
LL a[50],s[50];
LL n,t,ans;
void solve(LL k,LL sum)
{
    if(sum>t)  return ;
    if(sum+s[n]-s[k-1]<=ans) return;
    if(k==n+1)    {ans=max(ans,sum);return;}
    solve(k+1,sum+a[k]);
    solve(k+1,sum);
}
bool cmp(LL a,LL b){return a>b;}
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef CONGYU
    ifstream cin("testcase.in");
    #endif
    cin>>n>>t;
    for(int i=1;i<=n;i++)   cin>>a[i];
    

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)   s[i]=s[i-1]+a[i];
    if(s[n]<=t)
    {
        cout<<s[n]<<endl;
        return 0;
    }
    solve(1,0);
    cout<<ans<<endl;
}