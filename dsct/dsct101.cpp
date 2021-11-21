#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m;
vector<LL> c;

set<multiset<int>> dp[200000];
int main()
{
    

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    m=10000;
    c.push_back(0);

    auto start=chrono::system_clock::now();
    for(int i=1;i<=m;i*=2)
    {
        c.push_back(i);
        c.push_back(i);
    }
    LL n=c.size()-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=c[i];j--)
        {
            if(dp[j-c[i]].size()!=0)
            {
                multiset<int> tmp;
                for(auto s:dp[j-c[i]])
                {
                    tmp=s;
                    tmp.insert(c[i]);
                    dp[j].insert(tmp);
                }
            }
            else if(j==c[i])
            {
                multiset<int> tmp;
                tmp.insert(c[i]);
                dp[j].insert(tmp);
            }
        }
    }
    cout<<dp[m].size()<<endl;
    auto end=chrono::system_clock::now();
    auto d=chrono::duration_cast<chrono::microseconds>(end-start);
    cout<<double(d.count())*chrono::microseconds::period::num / chrono::microseconds::period::den<<endl;
    // for(int i=1;i<=m;i++)
    // {
    //     for(auto e:dp[i])
    //     {
    //         for(auto s:e)
    //         {
    //             cout<<s<<' ';
    //         }
    //         cout<<"\\";
    //     }
    //     cout<<endl;
    // }
}