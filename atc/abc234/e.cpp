#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL x;

int main()
{
    cin>>x;
    set<LL> s;
    for (int f = 1; f <= 9; f++)
    {
        for (int d = -9; d <= 8; d++)
        {
            string num;
            int k = f;
            for (int digit = 0; digit < 18; digit++)
            {
                num.push_back(k + '0');
                s.insert(stoll(num));
                k += d;
                if (k < 0 || k > 9)
                    break;
            }
        }
    }
    cout<<*(s.lower_bound(x))<<endl;
}