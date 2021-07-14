#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
const LL mod = 1e9 + 7;
#ifdef CONGYU
ifstream fin("testcase.in");
#endif
int Exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
}