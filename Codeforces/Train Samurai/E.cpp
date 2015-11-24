#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const double PI=acos(-1);

int a,b,c,r;

double X1,Y1,X2,Y2,X3,Y3,xx,yy;

double distance(double X1, double Y1, double X2, double Y2){
    return sqrt(sqr(X1-X2)+sqr(Y1-Y2));
}

double val(double X1, double Y1, double X2, double Y2, double X, double Y){
    double vx=Y2-Y1, vy=X1-X2;
    return vx*(X-X1) + vy*(Y-Y1);
}

bool same_side(double X1, double Y1, double X2, double Y2, double X3, double Y3, double x4, double y4){
    return (val(X1,Y1,X2,Y2,X3,Y3) * val(X1,Y1,X2,Y2,x4,y4) >= 0);
}

double inside(double x, double y){
    return same_side(X1,Y1,X2,Y2,xx,yy,x,y) && same_side(X2,Y2,X3,Y3,xx,yy,x,y) && same_side(X1,Y1,X3,Y3,xx,yy,x,y);
}

bool hpt(double a1, double b1, double c1, double a2, double b2, double c2, double &X, double &Y){
    double d=a1*b2-a2*b1;
    double dx=b1*c2-b2*c1;
    double dy=c1*a2-c2*a1;
    if(d==0) return 0;
    X=dx/d; Y=dy/d;
    return 1;
}

bool get_point(double X1, double Y1, double x0, double y0, double X2, double Y2, double &X, double &Y){
    double a1=Y1-y0, b1=x0-X1, c1=-a1*x0-b1*y0;
    double a2=Y2-y0, b2=x0-X2, c2=-a2*x0-b2*y0;
    for(int i=-1; i<=1; i+=2) for(int j=-1; j<=1; j+=2){
        double c11 = c1+r*i*sqrt(sqr(a1) + sqr(b1));
        double c22 = c2+r*j*sqrt(sqr(a2) + sqr(b2));
        if(hpt(a1,b1,c11,a2,b2,c22,X,Y)){
            if(inside(X,Y)) return 1;
        }
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>a>>b>>c>>r;
    X1=Y1=0;
    X2=a; Y2=0;

    double left=0, right=PI, mid;
    while(right-left>1e-11){
        mid=(left+right)/2;
        double xt=b, yt=0;
        X3=xt*cos(mid) - yt*sin(mid);
        Y3=xt*sin(mid) + yt*cos(mid);
        if(distance(X3,Y3,X2,Y2) > c) right=mid; else left=mid;
    }
    mid=(left+right)/2;
    double xt=b, yt=0;
    X3=xt*cos(mid) - yt*sin(mid);
    Y3=xt*sin(mid) + yt*cos(mid);

    xx=(X1+X2+X3)/3;
    yy=(Y1+Y2+Y3)/3;


    double i1,j1,i2,j2,i3,j3,res;
    if(get_point(X3,Y3,X1,Y1,X2,Y2,i1,j1) && get_point(X1,Y1,X2,Y2,X3,Y3,i2,j2) && get_point(X2,Y2,X3,Y3,X1,Y1,i3,j3)){
        double vX1=i2-i1, vY1=j2-j1;
        double vX2=i3-i1, vY2=j3-j1;
        res = fabs(vX1*vY2 - vX2*vY1)/2;
        res += r * ( distance(i1,j1,i2,j2) + distance(i2,j2,i3,j3) + distance(i3,j3,i1,j1) ) + PI * sqr(r);
    }else
        res=0;

    double p=(a+b+c);
    p/=2;

    double area = sqrt(p*(p-a)*(p-b)*(p-c));

    printf("%0.15lf\n",res/area);
}
