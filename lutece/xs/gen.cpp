#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int arr[N];
int n=10;
int main()
{
    srand(time(NULL));
    ofstream of;
    of.open("a.in");
    of<<n<<' '<<rand()%n<<endl;
    for(int i=1;i<=n;i++)
        of<<rand()%100<<' ';
}