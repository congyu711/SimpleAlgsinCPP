#include <bits/stdc++.h>
using namespace std;
int prime[200], cnt;
bool check[200];
long long int ans[200];
int main()
{
    int n = 6;
    for (int i = 2; i <= n; i++)
    {
        if (!check[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] * i <= n; j++)
        {
            check[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }

    for (int k = 2; k <= n; k++)
    {
        int i = k;
        while (i > 1)
        {
            for (int j = 0; j < cnt && prime[j] <= i; j++)
                if (i % prime[j] == 0)
                {
                    cout << i << ' ' << prime[j] << endl;
                    ans[j]++;
                    i /= prime[j];
                }
        }
    }
    long long int res = 1;
    for (int i = 0; i < cnt; i++)
    {
        //cout << prime[i] << ' ' << ans[i] << endl;
        res *= ans[i] + 1;
    }
    cout << res << endl;
}