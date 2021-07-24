#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const double eps=1e-6;
class point 
{
public:
    double x,y;
    point(double a,double b):x(a),y(b){}
    point():x(0),y(0){}
};

const point base(0,0);

double crossproduct(const point &a,const point &b)
{
    return (a.x-base.x)*(b.y-base.y)-(a.y-base.y)*(b.x-base.x);
}
bool cmp(const point &a,const point &b)
{
    if(fabs(crossproduct(a,b))<eps) return a.x<b.x;
    else    return crossproduct(a,b)>0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}