#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n;
LL c[N],sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i]>>sum[i];
        LL ans=0;
        LL cc=sum[i]/c[i];
        LL rem=sum[i]%c[i];
        ans+=(1LL*rem*(cc+1LL)*(cc+1LL));
        ans+=(c[i]-rem)*cc*cc;
        cout<<ans<<endl;
    }

}