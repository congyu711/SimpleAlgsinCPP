#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const LL mod = 1e9 + 7;
LL n;
class gd
{
public:
    LL a,b;
};
bool cmp(const gd& fst,const gd& snd)
{
    return fst.b<snd.b;
}
gd arr[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].a>>arr[i].b;
    }
    sort(arr+1,arr+n+1,cmp);
    int l=1,r=n;
    LL ans=0,alb=0;
    while(l<=r)
    {
        while(arr[l].b<=alb&&l<=r)
        {
            alb+=arr[l].a;
            ans+=arr[l].a;
            l++;
        }
        if(l>r)
        {
            cout<<ans<<endl;
            return 0;
        }
        LL cnt=min(arr[l].b-alb,arr[r].a);
        arr[r].a-=cnt;
        ans+=(2LL*cnt);
        alb+=cnt;

        if(arr[r].a==0) r--;
        if(r<l)
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}