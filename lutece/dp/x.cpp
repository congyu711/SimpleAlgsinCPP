#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 3e5 + 10;
LL n;
LL arr[N];
int tot;
LL val[N<<5],ch[N<<5][2];
void insert(LL x)
{
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int h=(x>>i)&1;
        if(ch[u][h]==0)
        {
            ch[tot][0]=ch[tot][1]=0;
            val[tot]=0;
            ch[u][h]=tot++;
        }
        u=ch[u][v];
    }
    val[u]=x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>arr[i];

}