#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;

class point
{
public:
    double x,y;
    point(double a,double b):x(a),y(b){}
    point():x(0),y(0){}
};

class _vector
{
public:
    double x,y;
    _vector(point st,point ed)
    {
        x=ed.x-st.x;
        y=ed.y-st.y;
    }
    _vector()
    {
        x=0,y=0;
    }
};
double crossproduct(const _vector &a,const _vector &b)
{
    return a.x*b.y-a.y*b.x;
}
class polygon
{
public:
    vector<point> pts;
};
point base=point(0,0);
double crossproduct(const point &a,const point &b)
{
    return (a.x-base.x)*(b.y-base.y)-(a.y-base.y)*(b.x-base.x);
}
bool cmp1(const point &a,const point &b)
{
    if(fabs(crossproduct(a,b))<eps) return a.x<b.x;
    else    return crossproduct(a,b)>0;
}
bool cmp2(const point &a, const point &b)
{
    if(fabs(a.x-b.x)<eps)   return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    
}