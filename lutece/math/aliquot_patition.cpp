#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


//  for all i in range[1,n], variety of floor(n/i)  is O(sqrt(n))
int main()
{
    LL n;
    for(int l=1,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        //xxxx
    }
}