#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


namespace MR
{
    //探测底数，可以满足1e18
    LL p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    //int64内) LL p[15] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    //O(1)快速乘不取模
    LL mul(LL a, LL b, LL m)
    {
        LL s = a * b - (LL)((long double)a * b / m + 0.5) * m;
        return s < 0 ? s + m : s;
    }
    LL fpow(LL x, LL a, LL m)
    {
        LL ans = 1;
        while (a)
        {
            if (a & 1)
                ans = mul(ans, x, m);
            x = mul(x, x, m), a >>= 1;
        }
        return ans;
    }
    int detect(LL n, LL a)
    {
        if (n == a)
            return 1;
        if (a % n == 0)
            return 1;
        LL now = n - 1, lst = 1;
        if (fpow(a, now, n) != 1)
            return 0;
        while (!(now & 1))
        {
            now /= 2;
            LL p = fpow(a, now, n);
            if (lst == 1 && p != 1 && p != n - 1)
                return 0;
            lst = p;
        }
        return 1;
    }

    LL MR(LL n)
    {
        if (n < 2)
            return 0;
        for (int i = 0; i < 10; ++i)
        {
            if (!detect(n, p[i]))
                return 0;
        }
        return 1;
    }
}
namespace PollardRho
{
    using namespace MR;
    LL PR(LL n)
    {
        mt19937 gen(time(nullptr));
        LL c=gen()%(n-1)+1;
        auto f=[&](LL x)->LL{return(x*x+c)%n;};
        LL a=f(0),b=f(a);
        while(a!=b)
        {
            LL d=__gcd(abs(a-b),n);
            if(d>1) return d;
            a=f(a);
            b=f(f(b));
        }
        return n;
    }
}

int main()
{
    LL n;
    while(cin>>n)
    {
        cout<<PollardRho::PR(n)<<endl;
    }
}