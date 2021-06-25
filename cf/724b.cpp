#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n;

void solve()
{
    string s;
    cin >> n;
    cin >> s;
    bool f = 0;
    for (int c = 0; c <= 25; c++)
    {
        f = 0;
        char cc = ('a' + c);
        for (int i = 0; i < s.length(); i++)
        {
            if (cc == s[i])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            cout << cc << endl;
            return;
        }
    }
    for (int c = 0; c <= 25; c++)
    {
        for (int cc = 0; cc <= 25; cc++)
        {
            f = 0;
            char c1 = ('a' + c), c2 = ('a' + cc);
            for (int i = 0; i < s.length() - 1; i++)
            {
                if (c1 == s[i] && c2 == s[i + 1])
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                cout << c1 << c2 << endl;
                return;
            }
        }
    }
    for (int c = 0; c <= 25; c++)
    {
        for (int cc = 0; cc <= 25; cc++)
        {
            for (int ccc = 0; ccc <= 25; ccc++)
            {
                f = 0;
                char c1 = ('a' + c), c2 = ('a' + cc), c3 = ('a' + ccc);
                for (int i = 0; i < s.length() - 2; i++)
                {
                    if (c1 == s[i] && c2 == s[i + 1] && c3 == s[i + 2])
                    {
                        f = 1;
                        break;
                    }
                }
                if (f == 0)
                {
                    cout << c1 << c2 << c3 << endl;
                    return;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}