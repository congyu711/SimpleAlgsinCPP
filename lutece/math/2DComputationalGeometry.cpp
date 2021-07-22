#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
const LL mod=1e9+7;
const double eps=1e-6;
const double inf=1e22;
const double pi=acos(-1);
class point
{
public:
    double x,y;
    point():x(0),y(0){}
    point(double a,double b):x(a),y(b){}
};
class _vector
{
public:
    double x,y;
    _vector():x(0),y(0){}
    _vector(point st,point ed)
    {
        x=ed.x-st.x;
        y=ed.y-st.y;
    }
    _vector(double a,double b):x(a),y(b){}
};
_vector operator+ (const _vector &a,const _vector &b)
{
    _vector res;
    res.x=a.x+b.x;
    res.y=a.y+b.y;
    return res;
}
_vector operator- (const _vector &a,const _vector &b)
{
    _vector res;
    res.x=a.x-b.x;
    res.y=a.y-b.y;
    return res;
}
double dot(const _vector &a,const _vector &b)
{
    return a.x*b.x+a.y*b.y;
}
class Line
{
public:
    point base;
    _vector dir;
    Line(point b,_vector d):base(b),dir(d){}
    Line(point a,point b)
    {
        base=a;
        dir=_vector(a,b);
    }
};

//vector on xoy plane, so the crossdot result can be 
//describe with only one number Z.
double crossdot(const _vector &a,const _vector &b)
{
    double z;
    z=a.x*b.y-a.y*b.x;
    return z;
}
//paositional_relationship_of_line_and_point
char linepointposition(Line &l,point p)
{
    if(l.dir.y<0)
    {
        l.dir.x=-l.dir.x;
        l.dir.y=-l.dir.y;
    }
    _vector bp(l.base,p);

    double z=crossdot(bp,l.dir);
    // cout<<z<<endl;
    if(z<eps)  return 'o';
    else if(z<0)    return 'd';
    else return 'u';
}
bool check_line_intersection(point sta,point eda,point stb,point edb)
{
    _vector dira(sta,eda),dirb(stb,edb);
    //parallel
    if(fabs(dira.x*dirb.y-dira.y*dirb.x)<eps)
    {
        if( sta.x<max(stb.x,edb.x)&&sta.x>min(stb.x,edb.x)||
            eda.x<max(stb.x,edb.x)&&eda.x>min(stb.x,edb.x)||
            stb.x<max(sta.x,eda.x)&&stb.x>min(sta.x,eda.x)||
            edb.x<max(sta.x,eda.x)&&edb.x>min(sta.x,eda.x))
            return true;
        else return false;
    }
    Line la(sta,eda),lb(stb,edb);
    char    lastb=linepointposition(la,stb),
            laedb=linepointposition(la,edb),
            lbsta=linepointposition(lb,sta),
            lbeda=linepointposition(lb,eda);
    if((lastb!=laedb||(lastb==laedb&&lastb=='o'))&&
        lbsta!=lbeda||(lbsta==lbeda&&lbsta=='o'))   return 1;
    else return 0;
}


class _vector3d
{
public:
    double x,y,z;
    _vector3d(double a,double b,double c):x(a),y(b),z(c){}
    _vector3d():x(0),y(0),z(0){}

};
_vector3d crossdot(const _vector3d &a,const _vector3d &b)
{
    _vector3d res(a.y*b.z-a.z*b.y,b.x*a.z-a.x*b.z,a.x*b.y-a.y*b.x);
    return res;
}
//Using homogeneous coordinates
point line_intersection(Line l1,Line l2)
{
    _vector3d   l1hc(l1.dir.y,-l1.dir.x,l1.dir.x*l1.base.y-l1.base.x*l1.dir.y),
                l2hc(l2.dir.y,-l2.dir.x,l2.dir.x*l2.base.y-l2.base.x*l2.dir.y);
    _vector3d res=crossdot(l1hc,l2hc);
    return point(res.x/res.z,res.y/res.z);
}



class polygon
{
public:
    vector<point> points;
};

//points of polygon must be marked COUNTERCLOCKWISED
double polygonarea(const polygon &a)
{
    const point base(0,0);
    int n=a.points.size();
    double res=0;
    for(int i=1;i<=n;i++)
    {
        _vector v1(base,a.points[i-1]),v2(base,a.points[i%n]);
        res+=crossdot(v1,v2);
    }
    return res;
}

//point in polygon
namespace PIP
{

//the ray is rightward;
//consider each edge:
//Horizontal edge will be ignored;
//if the ray meets a point, the point will be 
//counted if and only if this endpoint's y-coordinate is greater than another endpoint
bool raycasting(polygon plg,point p)
{
    auto pts=plg.points;
    pts.push_back(pts[0]);//form a loop
    int cnt=0;
    for(int i=0;i<pts.size()-1;i++)
    {
        _vector tmp(pts[i],pts[i+1]);
        if(fabs(tmp.y)<eps) continue;
        if(fabs(pts[i].y-p.y)<eps&&pts[i].y>pts[i+1].y) cnt++;
        else if(fabs(pts[i+1].y-p.y)<eps&&pts[i].y<pts[i+1].y)  cnt++;
        else if(check_line_intersection(pts[i],pts[i+1],p,point(inf,p.y)))   cnt++;
    }
    if(cnt&1)   return 1;//point inclusion in polygon
    else return 0;
}

bool windingnumber(polygon plg,point p)
{
    auto pts=plg.points;
    pts.push_back(pts[0]);//form a loop
    double d=0;
    for(int i=0;i<pts.size()-1;i++)
    {
        double k=atan2(pts[i].y-p.y,pts[i].x-p.x)-atan2(pts[i+1].y-p.y,pts[i+1].x-p.x);
        if(k>pi)    k=k-2*pi;
        else if(k<(-pi))  k=k+2*pi;
        d+=k;
    }
    if(fabs(d+2*pi)<eps)  return true;
    else return false;
}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // point a(0,0);
    // point b(-1,1);
    // Line l(a,b);
    // linepointposition(l,point(1,1));
    // cout<<check_line_intersection(point(0,0),point(3,3),point(3,0),point(0,3))<<endl;

    // using namespace PIP;
    // polygon a;
    // a.points.push_back(point(0,0));
    // a.points.push_back(point(1,0));
    // a.points.push_back(point(1,1));
    // a.points.push_back(point(0,1));
    // cout<<windingnumber(a,point(0.5,0.5))<<endl;
}