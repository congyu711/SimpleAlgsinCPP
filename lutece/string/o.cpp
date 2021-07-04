#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e6 + 10;
const LL maxn=1e16;
LL n,k,s;
LL a[30];
vector<LL> f;
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef CONGYU
    ifstream cin("testcase.in");
    #endif
    
    f.push_back(1);
    while(1)
    {
        LL c=f.size(),pre=f[c-1];
        if(c*pre>=maxn) break;
        f.push_back(c*pre);
    }
    
}