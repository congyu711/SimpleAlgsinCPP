#include<bits/stdc++.h>
using namespace std;

const int n=10;
const double e=1e7;
int main()
{
    mt19937 mt(time(nullptr));
    ofstream of("polygon.in");
    of.setf(ios::fixed,ios::floatfield);
    of<<n<<"\n";

    for(int i=1;i<=n;i++)
    {
        of<<double(mt())/e<<' '<<double(mt())/e<<"\n";
    }
}