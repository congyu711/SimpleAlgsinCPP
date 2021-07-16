#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL n,f;
LL a[N];
LL ans;
bool half(int x)
{
    for(int i=0;i<=20;i++)
    {
        if((1<<i)==x)   return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==-1)    f=i;
    }
    if(f==n)
    {
        cout<<0<<endl;
        return 0;
    }
    int tot=log2(n);
    int bp=log2(f);
    // cout<<bp<<endl;
    ans+=a[n];
    priority_queue<int> pq;
    for(int i=n-1;i>f;i--)
    {
        pq.push(-a[i]);
        if(half(i))
        {
            // cout<<ans<<endl;
            ans+=(-pq.top());
            pq.pop();
        }
    }
    cout<<ans<<endl;
}