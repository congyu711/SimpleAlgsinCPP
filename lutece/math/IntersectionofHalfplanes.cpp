#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;

class point
{
public:
    double x,y;
    point(double a,double b):x(a),y(b){}
    point():x(0),y(0){}
    friend ostream& operator<<(ostream &os,const point &p)
    {
        os<<'('<<p.x<<", "<<p.y<<')';
        return os;
    }
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

// point base=point(0,0);
double crossproduct(const point &a,const point &b,const point &base)
{
    return (a.x-base.x)*(b.y-base.y)-(a.y-base.y)*(b.x-base.x);
}
bool crossproductcmp(const point &a,const point &b)
{
    if(fabs(crossproduct(a,b,point(0,0)))<eps) return a.x<b.x;
    else    return crossproduct(a,b,point(0,0))>0;
}
bool xycmp(const point &a, const point &b)
{
    if(fabs(a.x-b.x)<eps)   return a.y<b.y;
    return a.x<b.x;
}

//segments are directed: from point a to point b
class segment
{
public:
    point a,b;
    double angle;
    segment(){}
    segment(point _a,point _b):a(_a),b(_b){}
    segment(double ax,double ay,double bx,double by)
    {
        a.x=ax,a.y=ay,b.x=bx,b.y=by;
    }
    double getangle()
    {
        return angle=atan2(b.y-a.y,b.x-a.x);
    }
};
point lineintersection(const segment &j,const segment &k)
{
    point res,p1=j.a,p2=j.b,p3=k.a,p4=k.b;
    double t1=crossproduct(p1,p4,p3);
    double t2=crossproduct(p2,p4,p3);
    res.x=(t1*p2.x-t2*p1.x)/(t1-t2);
    res.y=(t1*p2.y-t2*p1.y)/(t1-t2);
    return res;
}
bool pointsegtest(const point &p, const segment &s)
{
    if(crossproduct(p,s.b,s.a)<eps) return true;
    else return false;
}
void intersectionofHalfplanes(vector<segment> &v)
{
    int n=v.size();
    for(auto &s:v)   s.getangle();
    auto segcmp=[&](const segment &j,const segment &k)->bool{
        if(fabs(j.angle-k.angle)<eps)   return pointsegtest(j.a,k);
        return j.angle<k.angle;
    };
    sort(v.begin(),v.end(),segcmp);
    vector<segment> arr;
    arr.push_back(v[0]);
    for(int i=1;i<v.size();i++)
        if(v[i].angle-arr.back().angle>eps)   arr.push_back(v[i]);
    n=arr.size();
    deque<segment> dq;
    dq.push_back(arr[0]),dq.push_back(arr[1]);
    for(int i=2;i<n;i++)
    {
        while(dq.size()>1&&
        !pointsegtest(lineintersection(*(dq.end()-1),*(dq.end()-2)),arr[i]))
        dq.pop_back();
        while(dq.size()>1&&
        !pointsegtest(lineintersection(*(dq.begin()),*(dq.begin()+1)),arr[i]))
        dq.pop_front();
        dq.push_back(arr[i]);
    }
    while(dq.size()>1&&
    !pointsegtest(lineintersection(*(dq.end()-1),*(dq.end()-2)),*dq.begin()))
    dq.pop_back();
    while(dq.size()>1&&
    !pointsegtest(lineintersection(*(dq.begin()),*(dq.begin()+1)),*(dq.end()-1)))
    dq.pop_front();
}
int main()
{
    
}