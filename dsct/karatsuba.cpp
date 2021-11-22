#include<bits/stdc++.h>
using namespace std;

typedef vector<short> bigint;
typedef unsigned long long ULL;
void print(bigint c)
{
    reverse(c.begin(),c.end());
    for(auto e:c)   cout<<e;
}
bigint ulltobigint(ULL n)
{
    bigint res;
    while(n)
    {
        res.push_back(n%10);
        n/=10;
    }
    // reverse(res.begin(),res.end());
    return res;
}
bigint add(bigint a,bigint b)
{
    auto maxz=max(a.size(),b.size()),minz=min(a.size(),b.size());
    bigint res;
    short carry=0;
    for(int i=0;i<minz;i++)
    {
        auto c=a[i]+b[i]+carry;
        res.push_back(c%10);
        carry=c/10;
    }
    if(a.size()<b.size())   swap(a,b);
    for(int i=minz;i<maxz;i++)
    {
        auto c=a[i]+carry;
        res.push_back(c%10);
        carry=c/10;
    }
    if(carry)   res.push_back(carry);
    return res;
}
bigint leftshift(bigint c,int n)
{
    bigint res;
    while(n--)  res.push_back(0);
    for(auto e:c)   res.push_back(e);
    return res;
}
//a.size()==b.size(),   if doesn't add prefix 0;
bigint karatsuba(bigint a,bigint b)
{
    while(a.size()<b.size())    a.push_back(0);
    while(b.size()<a.size())    b.push_back(0);
    bigint res,la,ra,lb,rb;
    if(a.size()==0) return ulltobigint(0);
    if(a.size()==1) return ulltobigint(a[0]*b[0]);
    int m=a.size()/2,sz=a.size();
    for(int i=0;i<m;i++)
    {
        rb.push_back(b[i]);
        ra.push_back(a[i]);
    }
    for(int i=m;i<a.size();i++)
    {
        la.push_back(a[i]);
        lb.push_back(b[i]);
    }


    res=leftshift(karatsuba(la,lb),m*2);
    res=add(res,leftshift(add(karatsuba(la,rb),karatsuba(ra,lb)),m));
    res=add(res,karatsuba(ra,rb));
    return res;
}
int main()
{
    print(karatsuba(ulltobigint(11),ulltobigint(111)));
    cout<<endl<<111*11<<endl;
}