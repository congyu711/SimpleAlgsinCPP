#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
const LL mod=1e9+7;
// #ifdef CONGYU
//     ifstream fin("testcase.in");
// #endif
//a(n) = Sum_{k=1..n} mu(n/gcd(n,k))*sigma(gcd(n,k)).
bool vis[N];
int prime[N],o[N],m[N],a1[N],a0[N],f[N];
int n,tot;
int minp[N],ppow[N];//最小质因子次数，能约掉最小质因子的k次方
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vis[1]=1;o[1]=1;m[1]=1;a1[1]=1;a0[1]=1;f[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            prime[++tot]=i;
            minp[i]=1;
            ppow[i]=i;
            o[i]=i-1;a0[i]=2;a1[i]=i+1;m[i]=-1;
        }
        for(int j=1;j<=tot;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                minp[i*prime[j]]=minp[i]+1;
                ppow[i*prime[j]]=ppow[i]*prime[j];

                break;
            }
            //这里的数都是被一个最小质因子筛掉了
            minp[i*prime[j]]=1;
            ppow[i*prime[j]]=prime[j];

        }
    }
}