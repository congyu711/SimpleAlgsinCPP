#include"sge.h"
using namespace std;
double scalingfactor;
// ofstream fout("log.out");

void perspectiveprojection(vector<sf::ConvexShape> &vec,const object &obj,const camera &cmr)
{
    vec.clear();
    for(auto tria:obj.tris)
    {
        sf::ConvexShape tmp;tmp.setPointCount(3);
        tmp.setFillColor(sf::Color::Transparent);
        tmp.setOutlineColor(sf::Color::Red);
        tmp.setOutlineThickness(1);
        for(int idx=0;idx<3;idx++)
        {
            auto t=tria.pts[idx];
            vec3d op=t-cmr.pos;
            double veclen=getlen(cmr.dir);
            double projlen=dotprdt(cmr.dir,op)/veclen;
            double scaling=veclen/projlen;
            vec3d op1=op*(veclen/projlen);
            vec3d id=op1-cmr.dir;
            
            auto lambda=[&](double src,int bits) ->double{
                stringstream ss;double f;
                ss<<fixed<<setprecision(bits)<<src;
                ss>>f;
                return f;
            };
            // cout<<id.z<<endl;
            double  xx=lambda(-lambda(id.y*scalingfactor,2)+cmr.snwidth/2,1),
                    yy=lambda(-lambda(id.z*scalingfactor,2)+cmr.snheight/2,1);
            tmp.setPoint(idx,sf::Vector2f(xx,yy));
            // fout<<xx<<" "<<yy<<"\n";
        }

        vec.push_back(tmp);
        // fout<<"\n";
    }
}
int main()
{

    camera cmr;
    cmr.snheight=720;
    cmr.snwidth=1280;
    cmr.pos=vec3d(-2,0,0);
    cmr.dir=vec3d(1,0,0);
    scalingfactor=200;

    object o;
    o.tricnt=4;
    tri u;
    u.pts.push_back(vec3d(1,0,0)),u.pts.push_back(vec3d(0,1,0)),u.pts.push_back(vec3d(0,0,0)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,0,0)),u.pts.push_back(vec3d(0,1,0)),u.pts.push_back(vec3d(0,0,1)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,0,0)),u.pts.push_back(vec3d(0,0,0)),u.pts.push_back(vec3d(0,0,1)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(0,0,0)),u.pts.push_back(vec3d(0,1,0)),u.pts.push_back(vec3d(0,0,1)); o.tris.push_back(u); u.pts.clear();
    double rotate_angle=0;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML windows");
    window.setFramerateLimit(144);
    int64_t frms=1,fps=0;
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-Regular.ttf");

    //get start_time
    auto start=chrono::steady_clock::now();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        rotate_angle=(pi/60);
        for(auto &triangle:o.tris)
        {
            for(auto &point:triangle.pts)
            {
                double __dis=(point.x*point.x+point.y*point.y);
                point.x=cos(rotate_angle)*point.x-sin(rotate_angle)*point.y;
                point.y=sin(rotate_angle)*point.x+cos(rotate_angle)*point.y;
                if((point.x*point.x+point.y*point.y)<1e-8)   continue;
                point.x*=sqrt(__dis/(point.x*point.x+point.y*point.y));
                point.y*=sqrt(__dis/(point.x*point.x+point.y*point.y));
            }
        }

        vector<sf::ConvexShape> vec;
        perspectiveprojection(vec,o,cmr);
        window.clear();
        for(auto e:vec)
        {
            window.draw(e);
        }

        //get fps
        frms++;
        if(frms>500) frms=0,start=chrono::steady_clock::now();
        auto nw=chrono::steady_clock::now();
        chrono::duration<double> eps_sec=nw-start;
        fps=(int)round((double)frms/eps_sec.count());
        sf::Text t(to_string(fps),font,30);
        t.setColor(sf::Color::Green);
        t.setPosition(0,0);
        window.draw(t);



        window.display();
    }
    return 0;
}
/*compile
cd "/home/congyu/wsl2_cpp/lutece/math/SimpleGraphicsEngine" && g++ sge.cpp -o sge -lsfml-window -lsfml-graphics -lsfml-system && ./sge
*/