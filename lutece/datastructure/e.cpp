#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL n, m, x, k;
LL arr[N << 1];
LL cha[N << 1];
bool check(LL mid)
{
    memset(cha,0,sizeof(cha));
    for (int i = 1; i <= n; i++)
        cha[i] = arr[i] - arr[i - 1];
    cha[1] -= mid;
    int cnt = 0;
    LL sum=0;
    for (int i = 1; i <= n; i++)
    {
        sum+=cha[i];
        while (sum < 0)
        {
            cnt++;
            if (cnt > m)
            {
                return 0;
            }
            sum += k;
            cha[i + 2 * x + 1] -= k;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> x >> k;
    LL l=0,r=1e7+1,mid;
    for (int i = 1; i <= n; i++)
        {cin >> arr[i];r=min(r,arr[i]);}
    r+=m*k+1;
    while(l+1<r)
    {
        mid=l+r>>1;
        if(check(mid))
            l=mid;
        else    r=mid;
    }
    cout<<l<<endl;
}