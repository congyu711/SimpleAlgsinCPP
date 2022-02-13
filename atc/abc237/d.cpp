#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
string s;
list<int>::iterator p[N];

int main()
{
    ios::sync_with_stdio(false);
    list<int> ls;
    int n;
    cin>>n;
    cin>>s;
    ls.push_back(0);p[0]=ls.begin();
    for(int i=1;i<=n;i++)
    {
        auto u=s[i-1];
        auto it=p[i-1];
        if(u=='L')
        {
            if(it==ls.begin())
            {
                ls.push_front(i);
                p[i]=ls.begin();
            }
            else
            {
                p[i]=ls.insert(it--,i);
            }
        }
        else
        {
            auto e=it;
            if(++e==ls.end())
            {
                ls.push_back(i);
                p[i]=++it;
            }
            else
            {
                p[i]=ls.insert(++it,i);
            }
        }
    }
    for(auto i=ls.begin();i!=ls.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;
}