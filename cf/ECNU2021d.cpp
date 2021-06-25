//wrong answer on test 4
//改日再改
#include <bits/stdc++.h>
using namespace std;
const int n = 1e7 + 1;
int prime[n / 2], check[n], cnt = 0;

int getn(int p,int x)
{
    int ans=0;
    for(int i=2;i<=x;i++)
    {
        int pp=p;
        while(i%pp==0)
        {
            pp*=p;
            ans++;
        }
    }
    return ans;
}
void solve()
{
    int l, r, ll, rr;
    cin >> l >> r >> ll >> rr;
    int ccc=max(r,rr);
    for(int i=0;i<cnt&&prime[i]<=ccc;i++)
    {
        long long int c1=getn(prime[i],r)+getn(prime[i],ll-1);
        long long int c2=getn(prime[i],rr)+getn(prime[i],l-1);
        if(c1>c2)   {cout<<"No"<<endl;return;}
    }
    cout<<"Yes"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= n; i++)
    {
        if (!check[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] <= n; j++)
        {
            check[i * prime[j]] = 1;
            if (i % prime[j])
                break;
        }
    }
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}
