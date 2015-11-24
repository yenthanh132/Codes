#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const double EPS = 1e-9;

struct Point{
    double x,y;
    Point(){}
    Point(double _x, double _y){
        x=_x; y=_y;
    }
    Point operator-(Point p){
        return Point(p.x-x, p.y-y);
    }
    Point operator+(Point p){
        return Point(p.x+x, p.y+y);
    }
    Point operator/(double d){
        return Point(x/d,y/d);
    }
    double norm(){
        return x*x+y*y;
    }
    double len(){
        return hypot(x,y);
    }
};

struct Circle{
    double x,y,r;
    Circle(){}
    Circle(double _x, double _y, double _r){
        x=_x; y=_y; r=_r;
    }
    Circle(Point p, double _r){
        x=p.x; y=p.y; r=_r;
    }
};

struct SmallestClosingCircle{
    vector<Point> ds;

    void add(Point p){ ds.pb(p); }

    Circle getCircle(){
        random_shuffle(ds.begin(),ds.end());
        Circle c = Circle(ds[0],0);
        int n=sz(ds);
        for(int i=1; i<n; ++i)
            if((ds[i]-Point(c.x,c.y)).len() > c.r + EPS){
                c = Circle(ds[i],0);
                for(int j=0; j<i; ++j)
                    if((ds[j]-Point(c.x,c.y)).len() > c.r +EPS){
                        c = Circle( (ds[i]+ds[j])/2, (ds[i]-ds[j]).len()/2 );
                        for(int k=0; k<j; ++k)
                            if((ds[k]-Point(c.x,c.y)).len() > c.r + EPS){
                                c=makeCircle(ds[i],ds[j],ds[k],c);
                            }
                    }
            }

        return c;
    }

    Circle makeCircle(Point a, Point b, Point c, Circle res){
        double d = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
        d*=2;
        if(d==0) return res;
        double x = (a.norm()*(b.y-c.y) + b.norm()*(c.y-a.y) + c.norm()*(a.y-b.y))/d;
        double y = (a.norm()*(c.x-b.x) + b.norm()*(a.x-c.x) + c.norm()*(b.x-a.x))/d;
        return Circle(x,y,hypot(x-a.x,y-a.y));
    }
};

int main(){
    //freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--){
        SmallestClosingCircle obj;
        int n;
        double x,y;
        scanf("%d",&n);
        for(int i=0; i<n; ++i){
            scanf("%lf%lf",&x,&y);
            obj.add(Point(x,y));
        }
        Circle c = obj.getCircle();
        printf("%.2lf\n%.2lf %.2lf\n",c.r,c.x,c.y);
    }

}
