#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=20;i++)
    {
        cout<<a<<' '<<b<<' '<<a*b/__gcd(a,b)<<endl;
        a++,b++;
        if(i==abs(a-b)) cout<<endl;
    }
}