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
vector<point> convexhull;

//I suddenly find it wrong, fix later
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
    sort(points.begin(),points.end(),cmp1);
    convexhull.push_back(points[0]),convexhull.push_back(base);
    for(int i=1;i<points.size();i++)
    {
        while(convexhull.size()>=2&&
        crossproduct(_vector(convexhull[convexhull.size()-2],points[i]),
        _vector(convexhull[convexhull.size()-2],convexhull[convexhull.size()-1]))>=0)
            convexhull.pop_back();
        convexhull.push_back(points[i]);
    }
}
void Andrew(const polygon &p)
{
    auto points=p.pts;
    sort(points.begin(),points.end(),cmp2);
    vector<point> ch1,ch2;
    for(int i=0;i<points.size();i++)
    {
        if(ch1.size())  base=*(ch1.end()-1);
        while(ch1.size()>=2&&
        crossproduct(_vector(ch1[ch1.size()-2],points[i]),
        _vector(ch1[ch1.size()-2],ch1[ch1.size()-1]))>=0)
            ch1.pop_back();
        ch1.push_back(points[i]);
    }
    for(int i=points.size()-2;i>=0;i--)
    {
        if(ch2.size())  base=*(ch2.end()-1);
        while(ch2.size()>=2&&
        crossproduct(_vector(ch2[ch2.size()-2],points[i]),
        _vector(ch2[ch2.size()-2],ch2[ch2.size()-1]))>=0)
            ch2.pop_back();
        ch2.push_back(points[i]);
    }
    for(auto e:ch1) convexhull.push_back(e);
    for(auto e:ch2) convexhull.push_back(e);
    convexhull.pop_back();
}

int main()
{
    polygon p;
    ifstream fin("polygon.in");
    ofstream fout("convexhull.out");
    int n;
    fin>>n;
    double a,b;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        p.pts.push_back(point(a,b));
    }
    Andrew(p);
    cout<<base.x<<' '<<base.y<<endl;
    fout<<convexhull.size()<<endl;
    for(auto e:convexhull)
        fout<<e.x<<' '<<e.y<<endl;
}