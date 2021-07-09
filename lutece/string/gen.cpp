#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream outfile("testcase.in");
    outfile<<"250 250"<<endl;
    for(int i=1;i<=250;i++)
    {
        for(int j=1;j<=250;j++)
            outfile<<'a';
        outfile<<endl;
    }
}