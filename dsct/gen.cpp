#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n=1e6;
    int k=30;
    mt19937 gen;
    ofstream fout("heap.in");
    fout<<n<<' '<<k<<endl;
    for(int i=1;i<=n;i++)
    {
        fout<<gen()%2333<<endl;
    }
}