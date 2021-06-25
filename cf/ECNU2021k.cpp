//
#include <bits/stdc++.h>
using namespace std;
// int quickpow(int x, int a, int n)
// {
//     int ans = 1;
//     int c = x;
//     c%=n;
//     while (a)
//     {
//         if (a & 1)
//             ans *= c;
//         a >>= 1;
//         c *= c;
//         c %= n;
//         ans %= n;
//     }
//     return ans;
// }
// bool millerRabbin(int n)
// {
//     if (n < 3)
//         return n == 2;
//     int a = n - 1, b = 0;
//     while (a % 2 == 0)
//         a /= 2, ++b;
//     for (int i = 1, j; i <= 6; ++i)
//     {
//         int x = rand() % (n - 2) + 2, v = quickpow(x, a, n);
//         if (v == 1 || v == n - 1)
//             continue;
//         for (j = 0; j < b; ++j)
//         {
//             v = (long long)v * v % n;
//             if (v == n - 1)
//                 break;
//         }
//         if (j >= b)
//             return 0;
//     }
//     return 1;
// }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l, k;
    cin >> l >> k;
    if(l==2&&(k==1||k==2||k==3))    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
