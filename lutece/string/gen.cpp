#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream outfile("testcase.in");
    outfile<<"40 "<<rand()<<endl;
    for(int i=1;i<=40;i++)
    {
        outfile<<rand()<<endl;
    }
}