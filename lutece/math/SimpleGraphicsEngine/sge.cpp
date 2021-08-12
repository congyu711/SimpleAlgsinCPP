#include"sge.h"
using namespace std;
double scalingfactor;


void getprojection(vector<sf::ConvexShape> &vec,const object &obj,const camera &cmr)
{
    vec.clear();
    for(auto tria:obj.tris)
    {
        sf::ConvexShape tmp;tmp.setPointCount(3);
        tmp.setFillColor(sf::Color::Transparent);
        tmp.setOutlineColor(sf::Color::Red);
        tmp.setOutlineThickness(2);
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
            tmp.setPoint(idx,sf::Vector2f(lambda(-lambda(id.y*scalingfactor,2)+cmr.snwidth/2,1),lambda(-lambda(id.z*scalingfactor,2)+cmr.snheight/2,1)));
            cout<<lambda(-(id.y*scalingfactor)+cmr.snwidth/2,1)<<' '<<lambda(-(id.z*scalingfactor)+cmr.snheight/2,1)<<endl;
        }

        vec.push_back(tmp);
    }
}

int main()
{

    camera cmr;
    cmr.snheight=720;
    cmr.snwidth=1280;
    cmr.pos=vec3d(-2,0,0);
    cmr.dir=vec3d(1,0,0);
    scalingfactor=100;

    object o;
    o.tricnt=4;
    tri u;
    u.pts.push_back(vec3d(1,0,0)),u.pts.push_back(vec3d(0,1,0)),u.pts.push_back(vec3d(0,0,0)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,0,0)),u.pts.push_back(vec3d(0,1,0)),u.pts.push_back(vec3d(0,0,1)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(1,0,0)),u.pts.push_back(vec3d(0,0,0)),u.pts.push_back(vec3d(0,0,1)); o.tris.push_back(u); u.pts.clear();
    u.pts.push_back(vec3d(0,0,0)),u.pts.push_back(vec3d(0,1,0)),u.pts.push_back(vec3d(0,0,1)); o.tris.push_back(u); u.pts.clear();
    //rotate
    double rotate_angle=pi/12;
    for(auto &triangle:o.tris)
    {
        for(auto &point:triangle.pts)
        {
            point.x=cos(rotate_angle)*point.x-sin(rotate_angle)*point.y;
            point.y=sin(rotate_angle)*point.x+cos(rotate_angle)*point.y;
        }
    }


    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML windows");
    window.setFramerateLimit(480);
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
        


        vector<sf::ConvexShape> vec;
        getprojection(vec,o,cmr);
        window.clear();
        for(auto e:vec) {window.draw(e);window.display();}

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