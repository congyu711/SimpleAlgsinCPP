#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream outf;
    outf.open("ta3.in");
    for(int i=1;i<=10;i++)
    {
        outf<<i<<' '<<rand()%20+1<<endl;
        outf<<-1<<endl;
        outf<<-1<<endl;
        outf<<-1<<endl;
    }
    for(int i=1;i<=6;i++)
    {
        outf<<i<<' '<<rand()%43+1<<endl;
    }
}