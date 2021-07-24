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
bool cmp(const point &a,const point &b)
{
    if(fabs(crossproduct(a,b))<eps) return a.x<b.x;
    else    return crossproduct(a,b)>0;
}
vector<point> convexhull;
void Graham(const polygon &p)
{
    //first find a point with minimum y; update base
    auto points=p.pts;
    double miny=1e15;
    for(auto e:points)
    {
        if(e.y<miny)
        {
            base.x=e.x,base.y=e.y;
            miny=e.y;
        }
    }
    //then sort points by angle
    sort(points.begin(),points.end(),cmp);
    convexhull.push_back(points[0]),convexhull.push_back(base);
    for(int i=1;i<points.size()-1;i++)
    {
        while(convexhull.size()>=2&&
        crossproduct(_vector(convexhull[convexhull.size()-2],points[i]),
        _vector(convexhull[convexhull.size()-2],convexhull[convexhull.size()-1]))>=0)
            convexhull.pop_back();
        convexhull.push_back(points[i]);
    }
}

int main()
{
    polygon p;
    ifstream fin("polygon.in");
    int n;
    fin>>n;
    double a,b;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        p.pts.push_back(point(a,b));
    }
    Graham(p);
    for(auto e:convexhull)
        cout<<e.x<<' '<<e.y<<endl;
}