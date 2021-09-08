#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
const LL mod=1e9+7;
bool vis[N];
int prime[N],f[N];
int n,tot;
int minp[N],ppow[N];//最小质因子次数，能约掉最小质因子的k次方

// 欧拉函数为例 f[N]
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    auto F=[&](LL p,LL k,LL p_k)->LL{return p_k-p_k/p;};
    vis[1]=1;f[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            prime[++tot]=i;
            minp[i]=1;
            ppow[i]=i;
            f[i]=F(i,1,i);
        }
        for(int j=1;j<=tot;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                minp[i*prime[j]]=minp[i]+1;
                ppow[i*prime[j]]=ppow[i]*prime[j];
                f[i*prime[j]]=F(prime[j],minp[i*prime[j]],ppow[i*prime[j]])*f[i/ppow[i]];
                break;
            }
            //这里的数都是被一个最小质因子筛掉了
            minp[i*prime[j]]=1;
            ppow[i*prime[j]]=prime[j];
            f[i*prime[j]]=f[i]*F(prime[j],1,prime[j]);
        }
    }
    for(int i=1;i<=n;i++)   cout<<f[i]<<endl;
}